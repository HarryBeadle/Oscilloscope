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

using namespace std;

double trigger = 1.39;

QVector<double> sample(SAMPLE_SIZE);
QVector<double> t(SAMPLE_SIZE);
QCustomPlot* plot;

int port;

class replotter : public QThread
{
private:
    QVector<double> sample_stored;
public:
    replotter(QVector<double> sample) {
        sample_stored = sample;
    }

    void run()
    {
        plot->graph(0)->setData(t, sample_stored);
        plot->replot();
    }
};

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

replotter* plotter;

class autoTrigger : public QThread
{

    void run()
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
                resample();
            }
        }
    }
};

class readings : public QThread
{

    void run()
    {
        bool maxFound = false;
        double firstMax = sample[0];
        int firstMaxIndex = 0;
        int secondMaxIndex = 0;

        for (int i = 1; i < SAMPLE_SIZE -1; i++){
            if (maxFound){
                if (sample[i] >= (0.95*firstMax)){
                    secondMaxIndex = i;
                }
            }else{
                if (sample[i] > firstMax){
                    firstMax = sample[i];
                    firstMaxIndex = i;
                }
                else{
                    if (sample[i+1] < firstMax){
                        maxFound = true;
                        i++; // next 2 are less, max found
                    }
                }
            }
        }

        if (! maxFound) freq = 0.0;
        else freq = FSAMP / (secondMaxIndex - firstMaxIndex);
    }
};

autoTrigger* autoTrig;
readings* measurements;

Window::Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);
    ui->customPlot->addGraph(0);
    ui->customPlot->addGraph(0);

    plot = ui->customPlot;

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

    on_triggerSpinBox_editingFinished();

    port = serialport_init("/dev/tty.usbserial-FTVTCYMO", 9600);

    resample();

    autoTrig = new autoTrigger();
    plotter = new replotter(sample);
}

void Window::forceTrigger()
{
    if (autoTrig->isRunning()) autoTrig->exit();
    resample();
    plotter = new replotter(sample);
    plotter->start();
    while (!(plotter->isFinished())) continue;
}

Window::~Window()
{
    delete ui;
}

void Window::on_pushButton_clicked()
{
    forceTrigger();
}

void Window::on_pushButton_5_clicked()
{
    // Auto Trigger Button
    autoTrig = new autoTrigger();
    autoTrig->start();
}

void Window::on_pushButton_2_clicked()
{
    // Save / Debug Button
    ofstream csvFile;
    csvFile.open("~/waveform.csv");
    for (int i = 0; i < SAMPLE_SIZE; i++) {
        qDebug() << -SAMPLE_SIZE/2 + i << ", " << sample[i] << endl;
        csvFile << -SAMPLE_SIZE/2 + i << ", " << sample[i] << endl;
    }
    csvFile.close();
}

void Window::on_pushButton_6_clicked()
{
    port = serialport_init("/dev/tty.usbserial-FTVTCYMO", 9600);
}

//void Window::on_triggerSpinBox_valueChanged(double value)
//{
//    trigger = value;
//    QVector<double> t_line(SAMPLE_SIZE);
//    for (int i = 0; i < SAMPLE_SIZE; i++) {
//        t_line[i] = trigger;
//    }
//    plot->graph(1)->setData(t, t_line);
//    plot->replot();
//}

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
