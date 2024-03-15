#include "processthread.h"
#include <QSemaphore>
#include <QSystemSemaphore>

ProcessThread::ProcessThread(QObject *parent, QString pw, QString sc, QString dt, int it){ : QThread(parent)
{
    password = pw;
    source = sc;
    dest = dt;
    iter = it;
}

void ProcessThread::run()
{
//    QSystemSemaphore *sem = new QSystemSemaphore("break_rar marker", 10, QSystemSemaphore::Open);
//    sem->acquire();

    QProcess *process = new QProcess();
    connect(process, &QProcess::readyRead, [=]() {
        QString read = process->readAll();
//        qDebug() << read;
        if(read.indexOf("All OK") != -1) {
            emit handlePassword(iter, password);
//            sem->release();
        }
        else if(read.indexOf("Total errors:") != -1) {
            process->terminate();
            emit handleError(iter, password);
//            sem->release();
            quit();
        }
    });

    QStringList commandline;
    commandline << "x" << "-p"+password << source << dest;

//    qDebug() << commandline.join(' ');

    process->setProgram("unrar");
    process->setArguments(commandline);
    process->start();

    process->waitForFinished();

    /*QString read = process->readAll();
    qDebug() << read;
    if(read.indexOf("All OK") != -1) {
        qDebug() << "PASSWORD" << password;
        emit handlePassword(password);
    }
    else if(read.indexOf("Total errors:") != -1) {
        process->terminate();
    }*/
}

void ProcessThread::readProcess() {
//    QString read = process->readAll();
//    qDebug() << read;
//    if(read.indexOf("All OK") != -1) {
//        qDebug() << "PASSWORD" << password;
//    }
//    else if(read.indexOf("Total errors:") != -1) {
//        process->terminate();
//    }
}
