#include "window.h"
#include "ui_window.h"
#include "qcustomplot.h"
#include "Libraries/arduino-serial/arduino-serial-lib.h"
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <Qthread>
#include <termios.h>

#define SAMPLE_SIZE 500
#define FSAMP 1000

using namespace std;

// Volatile Variables
volatile bool auto_die = false;

// Global Variables
double trigger = 1.39;
QVector<double> sample(SAMPLE_SIZE);
QVector<double> t(SAMPLE_SIZE);
QCustomPlot* plot;
int port;
bool autotrig_on = false;
double freq = 0;

// Start Thread Instances
replotter* plotter;
autoTrigger* autoTrig;
readings* measurement;
update_measurements* updater;

/* replotter class QThread
    initalised with a sample, plots that then exits */
replotter::replotter(QVector<double> sample) {
    sample_stored = sample;
}

void replotter::run(void)
{
    plot->graph(0)->setData(t, sample_stored);
    plot->replot();
}

/* resample fucntion
    discards the current buffer and fills it with new data */
void resample(void)
{
    //fseek(port,0,SEEK_END);
    tcflush(port, TCIFLUSH);
    int n;
    unsigned int b[1];
    b[0] = 0;
    for (int i = 0; i < SAMPLE_SIZE; i++) {
        do {
            n = read(port, b, 1);
        } while (n == 0 || n == -1);
        sample[i] = b[0] * (3.3/255);
    }
}

/* autoTrigger class QThread
    Runs the autotriggering mode */
void autoTrigger::run(void)
{
    while (1) {
        int n;
        unsigned int b[1];
        b[0] = 0;
        do {
            n = read(port, b, 1);
        } while (n == 0 || n == -1);
        sample.insert(0, (double) b[0] * (3.3/255));
        sample.pop_back();
        if ((sample[SAMPLE_SIZE/2] > trigger) && (trigger > sample[SAMPLE_SIZE/2 - 1])) {
            plotter = new replotter(sample);
            plotter->start();
            measurement = new readings();
            measurement->start();
            while (measurement->isRunning()) continue;
            updater->start();
            resample();
        }
        if (auto_die) {
            auto_die = false;
            return;
        }
    }
}

void readings::run(void)
{
    bool maxFound = false;
    double firstMax = sample[SAMPLE_SIZE/4];
    int firstMaxIndex = SAMPLE_SIZE/4;
    int secondMaxIndex = 0;

    for (int i = SAMPLE_SIZE/4; i < SAMPLE_SIZE; i++) {
        if (maxFound) {
            if (sample[i] >= (0.99*firstMax)) {
                secondMaxIndex = i;
                break;
            }
        } else {
            if (sample[i] > firstMax) {
                firstMax = sample[i];
                firstMaxIndex = i;
            }
            else{
                if (sample[i+3] < firstMax) {
                    maxFound = true;
                    i += 3; // next 2 are less, max found
                }
            }
        }
    }
    if (!maxFound) freq += 0.0;
    else freq += FSAMP / (secondMaxIndex - firstMaxIndex);
    freq /= 2;
}

update_measurements::update_measurements(Ui::Window* interface)
{
    ui = interface;
}

double freq_old = 0;

void update_measurements::run(void) {
    if (freq != freq_old) {
        ui->freqNumber->display(freq);
        freq_old = freq;
    }
}

Window::Window(QWidget *parent) : QMainWindow(parent), ui(new Ui::Window)
{
    // Setup the UI
    ui->setupUi(this);

    // Setup the graphs
    ui->customPlot->addGraph(0);
    ui->customPlot->addGraph(0);
    plot = ui->customPlot;
    // Genorate Time Scale
    for (int i = 0; i < SAMPLE_SIZE; i++) {
        t[i] = -SAMPLE_SIZE/2 + i;
    }
    // Give the axes some labels:
    plot->xAxis->setLabel("Time / Samples");
    plot->yAxis->setLabel("Magnitude / (3.3/255)V");
    // Set axes ranges, so we see all data:
    plot->xAxis->setRange(-SAMPLE_SIZE/2, SAMPLE_SIZE/2);
    plot->yAxis->setRange(-0.5, 3.8);
    plot->replot();
    plot->graph(1)->setPen(QPen(QColor(255, 0, 0)));

    // Initalise the graph and serial
    on_triggerSpinBox_editingFinished();
    on_pushButton_6_clicked();

    // Get an Inital Sample
    resample();

    // Fill the threads
    autoTrig = new autoTrigger();
    plotter = new replotter(sample);
    updater = new update_measurements(ui);
}

void Window::forceTrigger()
{
    if (autoTrig->isRunning()) auto_die = true;
    resample();
    plotter = new replotter(sample);
    plotter->start();
    while (!(plotter->isFinished())) continue;
}

// Destructor
Window::~Window()
{
    delete ui;
}

void Window::on_pushButton_clicked()
{
    // Force Trigger
    ui->pushButton_5->setText("Wait");
    resample();
    forceTrigger();
    ui->pushButton_5->setText("Run");
    autotrig_on = false;
}

void Window::on_pushButton_5_clicked()
{
    // Auto Trigger Button
    if (!(autotrig_on)) {
        auto_die = false;
        autoTrig = new autoTrigger();
        autoTrig->start();
        ui->pushButton_5->setText("Stop");
        autotrig_on = true;
    } else {
        auto_die = true;
        ui->pushButton_5->setText("Run");
        autotrig_on = false;
    }
}

void Window::on_pushButton_2_clicked()
{
    // Save / Debug Button
    ofstream csvFile;
    char* filePath = "/Users/harrybeadle/waveform.csv";
    csvFile.open(filePath);
    csvFile << (char*) ui->lineEdit->text().data() << " | 13/3/16" << endl;
    for (int i = 0; i < SAMPLE_SIZE; i++) {
        qDebug() << -SAMPLE_SIZE/2 + i << ", " << sample[i] << endl;
        csvFile << -SAMPLE_SIZE/2 + i << ", " << sample[i] << endl;
    }
    csvFile.close();
}

// Serial Connect Button
void Window::on_pushButton_6_clicked()
{
    port = serialport_init("/dev/tty.usbserial-FTVTCYMO", 9600);
    if (port == -1) {
        ui->pushButton_6->setText("Connect to Device");
    } else {
        ui->pushButton_6->setText("Connected");
    }
}

void Window::on_triggerSpinBox_editingFinished()
{
    trigger = ui->triggerSpinBox->value();
    QVector<double> t_line(SAMPLE_SIZE);
    for (int i = 0; i < SAMPLE_SIZE; i++) {
        t_line[i] = trigger;
    }
    plot->graph(1)->setData(t, t_line);
    plot->replot();
}

void Window::on_pushButton_3_clicked()
{
    plot->savePng("/Users/harrybeadle/waveform.png");
}
