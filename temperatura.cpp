#include "temperatura.h"
#include "ui_temperatura.h"


Temperatura::Temperatura(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Temperatura)
{
    ui->setupUi(this);
    connect(ui->dialCent,SIGNAL(valueChanged(int)),this,SLOT(cent2Far(int)));
    connect(ui->dialFar,SIGNAL(valueChanged(int)),this,SLOT(cent2Cent(int)));
    connect(ui->dialKel,SIGNAL(valueChanged(int)),this,SLOT(cent2Kel(int)));

    //Establecer el valor de  C F K
    ui->dialCent->setValue(0);
    ui->dialFar->setValue(32);
    ui->dialKel->setValue(273);
}

Temperatura::~Temperatura()
{
    delete ui;
}

void Temperatura::cent2Far(int valor)
{
    if(ui->dialCent->hasFocus())
    {
        float f = (valor * 1.8) + 32;
        float k = (valor + 273);
        ui->dialFar->setValue(f);
        ui->dialKel->setValue(k);
    }


}

void Temperatura::cent2Cent(int valor)
{
    if(ui->dialFar->hasFocus()){
    float c = (valor-32) * 0.56;
    ui->dialCent->setValue(c);
    float k = (c+273);
    ui->dialKel->setValue(k);
    }

}

void Temperatura::cent2Kel(int valor)
{
    if(ui->dialKel->hasFocus()){
    float c = (valor - 273);
    ui->dialCent->setValue(c);

    float f= (c)*(9.0/5+32);
    ui->dialFar->setValue(f);
    }

}

