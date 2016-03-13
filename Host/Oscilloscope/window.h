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
    void forceTrigger();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_6_clicked();
    void on_triggerSpinBox_editingFinished();

private:
    Ui::Window *ui;
};

class replotter : public QThread
{
private:
    QVector<double> sample_stored;
public:
    replotter(QVector<double> sample);
    void run(void);
};

class autoTrigger : public QThread
{
    void run(void);
};

class readings : public QThread
{
    void run(void);
};

class update_measurements : public QThread
{
public:
    Ui::Window* ui;
    update_measurements(Ui::Window* interface);
    void run(void);
};

#endif // WINDOW_H
