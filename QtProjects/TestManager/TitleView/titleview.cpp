#include "titleview.h"
#include "ui_titleview.h"

TitleView::TitleView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TitleView)
{
    ui->setupUi(this);
    ui->labelProject->setText(QString("IA-978"));
    ui->labelVersion->setText(QString("V1.1.2"));
}

TitleView::~TitleView()
{
    delete ui;
}


