#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "libs/geniobase.h"
#include "libs/ftdi.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Slider_BL_valueChanged(int value);
    void on_Slider_BLR_valueChanged(int value);
    void on_Slider_BiasR_valueChanged(int value);
    void on_Slider_VNFB_valueChanged(int value);
    void on_Slider_VPLoad_valueChanged(int value);
    void on_Slider_VNSF_valueChanged(int value);
    void on_Slider_VNAmp_valueChanged(int value);
    void on_Slider_VPAB_valueChanged(int value);
    void on_Update_clicked();

private:
    Ui::MainWindow *ui;
    //by Robert Eber
    FTDI* ftdi;
    GenioBase* genio;
};

#endif // MAINWINDOW_H
