#include "netform.h"
#include "ui_netform.h"

NetForm::NetForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NetForm)
{
    ui->setupUi(this);
    ui->lineEditPort->setText(QString("7600"));
}

NetForm::~NetForm()
{
    delete ui;
}
