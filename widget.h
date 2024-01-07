#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QNetworkAccessManager>

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
    static void ReplyFinished(QNetworkReply *reply);

private:
    Ui::Widget *ui;
    int cnt;
    QNetworkAccessManager *manager;
    QNetworkRequest request;
};
#endif // WIDGET_H
