#include "homewindow.h"
#include "ui_homewindow.h"

homewindow::homewindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::homewindow)
{
    ui->setupUi(this);
}

homewindow::~homewindow()
{
    delete ui;
}

void homewindow::GetShowHomeInterface()
{
    this->show();
}

void homewindow::on_ShowMscBtn_clicked()
{
    this->hide();
    emit ShowMscInterface();
}

void homewindow::on_ShowVdoBtn_clicked()
{
    this->hide();
    emit ShowVdoInterface();
}
