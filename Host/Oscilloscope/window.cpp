#include "window.h"
#include "ui_window.h"
#include "qcustomplot.h"
#include "Libraries/arduino-serial/arduino-serial-lib.h"
//#include <QextSerialPort.h>
#include <unistd.h>
#include <iostream>
#include <Qthread>

#define SAMPLE_SIZE 1000

using namespace std;

double trigger = 3.3/2;

QVector<double> sample(SAMPLE_SIZE);
QVector<double> t(SAMPLE_SIZE);
QCustomPlot* plot;

int port;

class getTrigger : public QThread
{
    void run()
    {
        while (1) {
            int n;
            unsigned int b[1];
            do {
                n = read(port, b, 1);
                usleep(100000);
            } while (n == 0 || n == -1);
            sample.insert(0, (double) b[0]);
            if (sample[SAMPLE_SIZE/2] < trigger * (255/3.3) < sample[SAMPLE_SIZE/2 - 1]) {
                // Triggered
                plot->graph(0)->setData(t, sample);
                plot->replot();
                qDebug() << t[SAMPLE_SIZE/2] << ", " << sample[SAMPLE_SIZE/2] << endl;
                usleep(100000);
            }
        }
    }
};

getTrigger* getTrig;

Window::Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window)
{

    getTrig = new getTrigger();

    ui->setupUi(this);
    ui->customPlot->addGraph();
    plot = ui->customPlot;

    for (int i = 0; i < SAMPLE_SIZE; i++) {
        t[i] = i;
    }

    port = serialport_init("/dev/tty.usbserial-FTVTCYMO", 9600);

}

void Window::forceTrigger(QCustomPlot *customPlot)
{
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
    forceTrigger(plot);
}

void Window::on_pushButton_5_clicked()
{
    // Connect Button
    getTrig->start();
}
