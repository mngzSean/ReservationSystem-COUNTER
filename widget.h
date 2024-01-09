#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QNetworkAccessManager>
#include "ApiDevice.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_btnCount_clicked();
    void get_count(int count);

private:
    Ui::Widget *ui;
    int cnt;
    ApiDevice *apiDevice;
};
#endif // WIDGET_H
