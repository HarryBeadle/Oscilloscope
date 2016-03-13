#include "window.h"
#include "ui_window.h"
#include "qcustomplot.h"
#include "Libraries/arduino-serial/arduino-serial-lib.h"
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <Qthread>

#define SAMPLE_SIZE 500

using namespace std;

double trigger = 3.3/2;

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
        plot->replot(QCustomPlot::RefreshPriority::rpImmediate);
    }
};

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
            sample.insert(0, (double) b[0]);
            sample.pop_back();
            if (sample[SAMPLE_SIZE/2] < 115.0 < sample[SAMPLE_SIZE/2 - 1]) {
                plotter = new replotter(sample);
                plotter->start();
                while (!(plotter->isFinished())) continue;
            }
        }
    }
};

autoTrigger* autoTrig;

Window::Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window)
{

    autoTrig = new autoTrigger();

    ui->setupUi(this);
    ui->customPlot->addGraph();
    plot = ui->customPlot;

    for (int i = 0; i < SAMPLE_SIZE; i++) {
        t[i] = -SAMPLE_SIZE/2 + i;
    }

    // Give the axes some labels:
    plot->xAxis->setLabel("Time / Samples");
    plot->yAxis->setLabel("Magnitude / (3.3/255)V");
    // Set axes ranges, so we see all data:
    plot->xAxis->setRange(-SAMPLE_SIZE/2, SAMPLE_SIZE/2);
    plot->yAxis->setRange(0, 255);
    plot->replot();

    port = serialport_init("/dev/tty.usbserial-FTVTCYMO", 9600);

}

void Window::forceTrigger()
{
    int n = -1;
    unsigned int b[1];
    b[0] = 0;
    for (int i = 0; i < SAMPLE_SIZE; i++) {
        do {
            n = read(port, b, 1);
        } while (n == 0 || n == -1);
        //sample.insert(0, (double) b[0]);
        //sample.pop_back();
        qDebug() << b[0] << endl;
        qDebug() << b << endl;
        sample[i] = (double) b[0];
    }
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
