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
    void on_pushButton_2_clicked();//clear
    void on_pushButton_3_clicked();//rotate
    void bresenham(int x1,int y1,int x2,int y2);
    int sign(int l);
    void mouseDoubleClickEvent(QMouseEvent *ev);
    void seedfill(int x,int y,QRgb bg);
    void arbitrary(int x1,int y1,int x2,int y2);
    void float_mult(float a[2][3],float b[3][3]);

private:
    Ui::MainWindow *ui;
    float a[2][3]; //input matrix
    float r[3][3]; //rotation matrix
    float c[2][3]; //output matrix

};
#endif // MAINWINDOW_H
