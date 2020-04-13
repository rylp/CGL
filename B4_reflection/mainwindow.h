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
    void on_pushButton_clicked();//reflection x
    void on_pushButton_2_clicked();//ref y
    void on_pushButton_3_clicked();//ref xy
    void on_pushButton_4_clicked();//arbitrary
    void on_pushButton_5_clicked();//draw
    void on_pushButton_6_clicked();//ori
    void reflectionX(float x1,float y1,float x2,float y2);
    void reflectionY(float x1,float y1,float x2,float y2);
    void reflectionXY(float x1,float y1,float x2,float y2);
    void arbitrary(float x1,float y1,float x2,float y2,float xa,float ya,float r);
    void float_mult(float a[2][3],float b[3][3]);
    void bresenham(float x1,float y1,float x2,float y2);
    int sign(int l);

private:
    Ui::MainWindow *ui;
//make everything float
    float a[2][3];//input matrix
    float rx[3][3];//reflection X matrix
    float ry[3][3];//reflection y matrix
    float rxy[3][3];//reflection XY matrix

    float arb[3][3];//abritrary matrix
    float c[2][3];//output matrix
};
#endif // MAINWINDOW_H
