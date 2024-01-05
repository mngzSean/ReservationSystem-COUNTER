#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , cnt(1)
{
    ui->setupUi(this);
    ui->lblCount->setText(QString::number(cnt));
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_btnCount_clicked()
{
    ui->lblCount->setText(QString::number(++cnt));
}
