#ifndef DEVICE_H
#define DEVICE_H

#include "ApiHandler.h"

class ApiDevice : public ApiHandler
{
    Q_OBJECT
private:
    ApiHandler *handler = nullptr;
    virtual void handle(QString path, QByteArray data) override;
public:
    void requestCount();
    void requestIssue();
signals:
    void replyCount(int result);
};

#endif // DEVICE_H
