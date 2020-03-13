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
    void on_pushButton_clicked();//draw
    void on_pushButton_2_clicked();//dda
    void on_pushButton_3_clicked();//bresenham
    void dda(int x1,int y1,int x2,int y2);
    void bresenham(int x1,int y1,int x2,int y2);
    int sign(int l);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
