#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "libs/geniobase.h"
#include "libs/ftdi.h"
#include "libs/func.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    genio = new GenioBase();
    ftdi = new FTDI();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete genio;
    delete ftdi;
}

void MainWindow::on_Update_clicked()
{
    Funkcije* Usb;
    Usb = new Funkcije(this->genio);
    //Usb -> openFTDIFIFO();
    int  H35DAC[8];

    H35DAC[0] = ui->spinBox_BL->value();
    H35DAC[1] = ui->spinBox_BLR->value();
    H35DAC[2] = ui->spinBox_BiasR->value();
    H35DAC[3] = ui->spinBox_VNFB->value();
    H35DAC[4] = ui->spinBox_VPLoad->value();
    H35DAC[5] = ui->spinBox_VNSF->value();
    H35DAC[6] = ui->spinBox_VNAmp->value();
    H35DAC[7] = ui->spinBox_VPAB->value();

    Usb -> SendDACSensor(H35DAC[7], false );
     Usb -> SendDACSensor(H35DAC[6], false );
      Usb -> SendDACSensor(H35DAC[5], false );
       Usb -> SendDACSensor(H35DAC[4], false );
        Usb -> SendDACSensor(H35DAC[3], false );
         Usb -> SendDACSensor(H35DAC[2], false );
          Usb -> SendDACSensor(H35DAC[1], false );
           Usb -> SendDACSensor(H35DAC[0], false );

     //Usb -> SendH35Config();
     // SendH35Config
     for (int icol=0; icol<38; icol++)
     {
       if( (37-icol) == ui->H35Col->value())// FormMain -> EditH35Col -> Text.ToInt() )
       {
           Usb->SendBitSensor(((37-icol) == 0)&&(ui->checkbox_AOutToMon->isChecked() == true));//MuxEn
           Usb->SendBitSensor(ui->checkbox_InjToPixel->isChecked());//InjToCol
           Usb->SendBitSensor(ui->checkbox_TestToMon->isChecked());//TestToMon
           Usb->SendBitSensor(ui->checkbox_InjToTest->isChecked());//InjToTest
       }
       else
       {
           Usb->SendBitSensor(((37-icol) == 0)&&(ui->checkbox_AOutToMon->isChecked() == true));//
           Usb->SendBitSensor(false);//
           Usb->SendBitSensor(false);//
           Usb->SendBitSensor(false);//
       }
     }//cols
     for (int irow=0; irow<8; irow++) {

       if( (7-irow) == ui->H35Row->value())//FormMain -> EditH35Row -> Text.ToInt() )
       {
           Usb->SendBitSensor(false);//nn
           Usb->SendBitSensor((7-irow) == ui->RowToAOut->value());//SF
           Usb->SendBitSensor(ui->checkbox_InjToPixel->isChecked());//Inj
           Usb->SendBitSensor(ui->checkbox_PixelToTest->isChecked());//Test
       }
       else
       {
           Usb->SendBitSensor(false);//nn
           Usb->SendBitSensor((7-irow) == ui->RowToAOut->value());//SF
           Usb->SendBitSensor(false);//
           Usb->SendBitSensor(false);//
       }

     }//rows

     Usb -> SendLoadDAC();

     Usb->SendBuffer();
}

void MainWindow::on_Slider_BL_valueChanged(int value)
{
    ui->spinBox_BL->setValue(value);
}

void MainWindow::on_Slider_BLR_valueChanged(int value)
{
    ui->spinBox_BLR->setValue(value);
}

void MainWindow::on_Slider_BiasR_valueChanged(int value)
{
    ui->spinBox_BiasR->setValue(value);
}

void MainWindow::on_Slider_VNFB_valueChanged(int value)
{
    ui->spinBox_VNFB->setValue(value);
}

void MainWindow::on_Slider_VPLoad_valueChanged(int value)
{
    ui->spinBox_VPLoad->setValue(value);
}

void MainWindow::on_Slider_VNSF_valueChanged(int value)
{
    ui->spinBox_VNSF->setValue(value);
}

void MainWindow::on_Slider_VNAmp_valueChanged(int value)
{
    ui->spinBox_VNAmp->setValue(value);
}

void MainWindow::on_Slider_VPAB_valueChanged(int value)
{
    ui->spinBox_VPAB->setValue(value);
}
