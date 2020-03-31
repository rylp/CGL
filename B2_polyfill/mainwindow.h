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
    void on_pushButton_clicked();//get col
    void bresenham(int x1,int y1,int x2,int y2);
    int sign(int l);
    void mousePressEvent(QMouseEvent *ev);
    void mouseDoubleClickEvent(QMouseEvent *ev);
    void seedfill(int x,int y,QRgb bg);

private:
    Ui::MainWindow *ui;

    int i;
    bool start;

    int a[10];//for storing x values
    int b[10];//for storing y values
};
#endif // MAINWINDOW_H
