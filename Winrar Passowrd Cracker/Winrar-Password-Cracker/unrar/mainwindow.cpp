#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QProcess>
#include <QPushButton>
#include <QString>
#include <QDebug>
#include <QRegularExpression>
#include <processthread.h>
#include <QSystemSemaphore>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pb_start, &QPushButton::clicked, this, &MainWindow::on_start);

    sem = new QSemaphore(200);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_start()
{
    mask = ui->le_mask->text();
    QString sets[10] = {
        ui->le_0->text(),
        ui->le_1->text(),
        ui->le_2->text(),
        ui->le_3->text(),
        ui->le_4->text(),
        ui->le_5->text(),
        ui->le_6->text(),
        ui->le_7->text(),
        ui->le_8->text(),
        ui->le_9->text()
    };

    source = ui->le_source->text();
    dest = ui->le_dest->text();
    iterator = 0;
    restored = false;

    dic.push_back({
                   "Hola", "HOLA", "hola", "h0l4",
                  });
    dic.push_back({"."});
    dic.push_back({"123", ""});
    dic.push_back({"bcc", ""});

    generatePassword("", 0);

    qDebug() << "ITERATIONS" << iterator;
}

void MainWindow::generatePassword(QString pw, int ind)
{
    if(restored) return;
    if(ind == dic.size()) {
        iterator++;
        start(pw, iterator);
        return;
    }
    for(int i=0; i<dic[ind].size(); i++) {
        generatePassword(pw + dic[ind][i], ind+1);
    }
}

void MainWindow::start(QString password, int iter)
{
    sem->acquire();
    ProcessThread *pt = new ProcessThread(this, password, source, dest, iter);
    connect(pt, &ProcessThread::finished, pt, &QObject::deleteLater);
    connect(pt, &ProcessThread::handlePassword, [=](int it, const QString &pw) {
        qDebug() << "PASSWORD" << it << pw;
        restored = true;
        sem->release();
    });
    connect(pt , &ProcessThread::handleError, [=](int it, const QString &pw) {
        if(restored) return;
        qDebug() << "ERROR ->" << it << pw;
        sem->release();
    });
    pt->start(QThread::LowestPriority);
}

