#include "window.h"
#include "ui_window.h"
#include "qcustomplot.h"
#include "Libraries/arduino-serial/arduino-serial-lib.h"
//#include <QextSerialPort.h>
#include <unistd.h>
#include <iostream>
#include <thread>

#define SAMPLE_SIZE 1000

using namespace std;

int port;

volatile bool triggered = false;
double trigger = 3.3/2;
QVector<double> sample(SAMPLE_SIZE);
QVector<double> t(SAMPLE_SIZE);

void checkTrigger(QCustomPlot* plot)
{
    while (1) {
        if (sample[SAMPLE_SIZE/2] < trigger * (3.3/255) < sample[SAMPLE_SIZE/2 - 1]) {
            triggered = true;
            plotSample(sample, plot);
        }
        int n;
        int b[1];
        do {
            n = read(port, b, 1);
        } while (n == -1 || n == 0);
        sample.insert(0, (double) b[0]);
    }
}

void plotSample(QVector<double> sample, QCustomPlot* plot)
{
    plot->graph(0)->setData(t, sample);
    plot->replot();
}

Window::Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);
    ui->customPlot->addGraph();

    for (int i = 0; i < SAMPLE_SIZE; i++) {
        t[i] = i;
    }

    class thread checkTriggerThread (checkTrigger, ui->customPlot);

}

void Window::forceTrigger(QCustomPlot *customPlot)
{
    //customPlot->clearGraphs();
    qDebug() << "Start" << endl;
    QVector<double> x(SAMPLE_SIZE), y(SAMPLE_SIZE); // initialize with entries 0..100
    unsigned int b[1];
    int n = -1;
    for (int i = 0; i < SAMPLE_SIZE; i++) {
        do {
            n = read(port, b, 1);
        } while (n == -1 || n == 0);
        y[i] = (double) b[0];
        x[i] = -SAMPLE_SIZE/2 + i;
        qDebug() << x[i] << ", " << y[i] << endl;
    }
    // create graph and assign data to it:
    customPlot->graph(0)->setData(x, y);
    //give the axes some labels:
    customPlot->xAxis->setLabel("Time / Samples");
    customPlot->yAxis->setLabel("Magnitude / (3.3/255)V");
    // set axes ranges, so we see all data:
    customPlot->xAxis->setRange(-SAMPLE_SIZE/2, SAMPLE_SIZE/2);
    customPlot->yAxis->setRange(0, 255);
    customPlot->replot();
}

Window::~Window()
{
    delete ui;
}

void Window::on_pushButton_clicked()
{
    forceTrigger(ui->customPlot);
}

void Window::on_pushButton_5_clicked()
{
    // Connect Button
    port = serialport_init("/dev/tty.usbserial-FTVTCYMO", 9600);
}

void Window::on_pushButton_14_clicked()
{
    qDebug() << "Not implimented" << endl;
//    while (1) {
//        plotData(ui->customPlot);
//        usleep(2e6);
//    }
}
