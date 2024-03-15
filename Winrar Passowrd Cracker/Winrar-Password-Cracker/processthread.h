#ifndef PROCESSTHREAD_H
#define PROCESSTHREAD_H

#include <QObject>
#include <QProcess>
#include <QThread>
#include <QDebug>
#include <QSystemSemaphore>

class ProcessThread : public QThread
{
    Q_OBJECT
public:
    explicit ProcessThread(QObject *parent = nullptr, QString pw = QString(), QString sc = QString(), QString dt = QString(), int it = 0);
    void run() override;

public slots:
    void readProcess();

signals:
    void handlePassword(int it, const QString &pw);
    void handleError(int it, const QString &pw);

private:
    QString password;
    QString source;
    QString dest;
    int iter;
};

#endif // PROCESSTHREAD_H
