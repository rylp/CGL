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

    void mousePressEvent(QMouseEvent *ev);
    void cohen(int,int,int,int);
    int compute(int,int);
    void DDA(int x1,int y1,int x2,int y2);

    ~MainWindow();

private slots:
    void on_pushButton_clicked(); //draw
    void on_pushButton_2_clicked(); //clear
    void on_pushButton_3_clicked(); //clip

private:
    Ui::MainWindow *ui;


    int inside;
    int left;
    int  right;
    int  bottom;
    int  top;

    int a[20],b[20];
    int i;
    bool start;
    int xmin,xmax,ymin,ymax;
};
#endif // MAINWINDOW_H
