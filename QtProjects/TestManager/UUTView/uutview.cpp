#include "uutview.h"
#include "ui_uutview.h"

UUTView::UUTView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UUTView)
{
    ui->setupUi(this);
}

UUTView::~UUTView()
{
    delete ui;
}
