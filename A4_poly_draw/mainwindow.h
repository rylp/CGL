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
    void on_pushButton_clicked();//getcolor
    void dda(int x1,int y1,int x2,int y2);
    void mousePressEvent(QMouseEvent *ev);

private:
    Ui::MainWindow *ui;

    int a[10];//array to store all x values
    int b[10];//array to store all y values

    int i;//initializer
    bool start;//to check when to end ie Right Click is done
};
#endif // MAINWINDOW_H
