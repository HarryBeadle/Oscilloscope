#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include "qcustomplot.h"

namespace Ui {
class Window;
}

void checkTrigger(QCustomPlot* plot);

void plotSample(QVector<double> sample, QCustomPlot* plot);

class Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = 0);
    ~Window();
    void forceTrigger(QCustomPlot *customPlot);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_14_clicked();

private:
    Ui::Window *ui;
};

#endif // WINDOW_H
