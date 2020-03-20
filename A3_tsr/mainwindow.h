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
    void on_pushButton_clicked();//trans
    void on_pushButton_2_clicked();//scale
    void on_pushButton_3_clicked();//rot
    void on_pushButton_4_clicked();//orig
    void on_pushButton_5_clicked();//draw
    void bresenham(int x1,int y1,int x2,int y2);
    int sign(int l);
    void translate(int x1,int y1,int x2,int y2,int tx,int ty);
    void scale(int x1,int y1,int x2,int y2,int sx,int sy);
    void rotate(int x1,int y1,int x2,int y2,float r1);
    void mult(int m1[2][3],int m2[3][3]);
    void float_mult(float m1[2][3],float m2[3][3]);


private:
    int a[2][3];//input for translate and scale
    int t[3][3]; //translation matrix
    int s[3][3]; //scaling matrix
    int c[2][2];  //resulting output matrix for translation and scaling

    float a1[2][3]; //input for rotate
    float r[3][3]; //rotation matrix
    float c1[2][3]; //resulting output for rotate
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
