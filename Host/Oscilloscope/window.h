#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include "qcustomplot.h"

namespace Ui {
class Window;
}

class Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = 0);
    ~Window();
    void plotData(QCustomPlot *customPlot);
    void plotTestData(QCustomPlot *customPlot);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Window *ui;
};

#endif // WINDOW_H
