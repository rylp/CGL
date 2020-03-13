#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"

QImage img(400,400,QImage::Format_RGB888);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked() //draw
{
    bresenham(50,50,350,50);
    bresenham(50,50,50,200);
    bresenham(50,200,350,200);
    bresenham(350,50,350,200);
    dda(50,125,200,50);
    dda(200,50,350,125);
    dda(350,125,200,200);
    dda(200,200,50,125);
    bresenham(125,87,275,87);
    bresenham(275,87,275,161);
    bresenham(275,161,125,161);
    bresenham(125,87,125,161);
    ui->label->setPixmap(QPixmap::fromImage(img));//always last statement in code

}

void MainWindow::on_pushButton_2_clicked() //dda
{
    int x1,y1,x2,y2;
    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();
    dda(x1,y1,x2,y2);

    ui->label->setPixmap(QPixmap::fromImage(img));

}

void MainWindow::on_pushButton_3_clicked() //bresenham
{
    int x1,y1,x2,y2;
    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();
    bresenham(x1,y1,x2,y2);

    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::dda(int x1, int y1, int x2, int y2)
{
    int i=0;
    float dx,dy;
    float leng;
    float xinc,yinc;

    QRgb v;
    v=qRgb(255,255,255);

    dx=x2-x1;
    dy=y2-y1;

    if(abs(dx)>=abs(dy))
    {
        leng=abs(dx);
    }
    else
    {
        leng=abs(dy);
    }

    xinc=dx/leng;
    yinc=dy/leng;

    float x=x1;
    float y=y1;

    while(i <= leng)
    {
        img.setPixel(x,y,v);
        x += xinc;
        y += yinc;
        i++;
    }
}

void MainWindow::bresenham(int x1, int y1, int x2, int y2)
{
    float dx,dy;
    float leng;
    float P;

    dx=abs(x2-x1);
    dy=abs(y2-y1);

    float x=x1;
    float y=y1;

    QRgb v;
    v = qRgb(255,0,0);

    if(dx>=dy) //m<1 ie x should always inc and y inc when P<0
    {
        P=2*dy-dx;
        int i=0;
        leng=dx;

        while(i <= leng)
        {
            img.setPixel(x,y,v);
            if(P<0)
            {
                P+=2*dy;
;            }
            else
            {
                P += 2*(dy-dx);
                y = y + 1*(sign(y2-y1));
            }
            x = x + (1*sign(x2-x1));
            i++;
        }
    }

    else //dy>dx   m>1 ie y should always inc and x inc when P<0
    {
        P=2*dx-dy;
        int i=0;
        leng=dy;

        while(i <= leng)
        {
            img.setPixel(x,y,v);
            if(P<0)
            {
                P+=2*dx;
;            }
            else
            {
                P += 2*(dx-dy);
                x = x + 1*(sign(x2-x1));
            }

            y = y + (1*sign(y2-y1));
            i++;
        }
    }
}

int MainWindow::sign(int l)
{
    if(l>=0)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
