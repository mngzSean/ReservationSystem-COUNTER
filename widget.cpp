#include "widget.h"
#include "ui_widget.h"
#include <QNetworkReply>
#include <QUrl>
#include <QString>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , cnt(1)
{
    ui->setupUi(this);
    ui->lblCount->setText(QString::number(cnt));

    manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &ReplyFinished);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_btnCount_clicked()
{
    ui->lblCount->setText(QString::number(++cnt));
    manager->get(QNetworkRequest(QUrl("http://localhost:5175/Device/counter")));
}

void Widget::ReplyFinished(QNetworkReply *reply)
{
    qDebug() << reply->url();
    QString answer = reply->readAll();
    qDebug() << answer;
}
