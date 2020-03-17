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
    void on_pushButton_2_clicked();//ddaline
    void on_pushButton_3_clicked();//dda_circ
    void on_pushButton_4_clicked();//bres_circ
    void ddaline(int x1,int y1,int x2,int y2);
    void ddacirc(int xc,int yc,int r);
    void brescirc(int xc,int yc,int r);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
