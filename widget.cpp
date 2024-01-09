#include "widget.h"
#include "ui_widget.h"
#include <QNetworkReply>
#include <QUrl>
#include <QString>
#include <QRegExp>
#include "ApiDevice.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , cnt(1)
{
    ui->setupUi(this);
    ui->lblCount->setText(QString::number(cnt));

    apiDevice = new ApiDevice();
    connect(apiDevice, &ApiDevice::replyCount, this, &Widget::get_count);
    apiDevice->requestCount();
}

Widget::~Widget()
{
    delete apiDevice;
    delete ui;
}

void Widget::get_count(int cnt)
{
    ui->lblCount->setText(QString::number(cnt));
}

void Widget::on_btnCount_clicked()
{
    apiDevice->requestIssue();
}
