#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();//solid
    void on_pushButton_2_clicked();//dotted
    void on_pushButton_3_clicked();//dashed
    void on_pushButton_4_clicked();//dash-dot
    void on_pushButton_5_clicked();//thick
    void solid(int x1,int y1,int x2,int y2);
    void dotted(int x1,int y1,int x2,int y2);
    void dashed(int x1,int y1,int x2,int y2);
    void dashdot(int x1,int y1,int x2,int y2);
    void thick(int x1,int y1,int x2,int y2);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
