#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QSemaphore>
#include <QSystemSemaphore>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void on_start();
    void start(QString password, int iter);
    void generatePassword(QString pw, int i);

private:
    Ui::MainWindow *ui;
    QString source;
    QString dest;
    QString mask;

    QVector<QVector<QString>> dic;
    int iterator;
    bool restored;

    QSemaphore *sem;
};
#endif // MAINWINDOW_H
