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
    ddacirc(150,150,50);
    brescirc(150,150,100);
    ddaline(150,50,64,200);
    ddaline(64,200,236,200);
    ddaline(236,200,150,50);

    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_2_clicked() //ddaline
{
   int x1,y1,x2,y2;
   x1=ui->textEdit->toPlainText().toInt();
   y1=ui->textEdit_2->toPlainText().toInt();
   x2=ui->textEdit_3->toPlainText().toInt();
   y2=ui->textEdit_4->toPlainText().toInt();
   ddaline(x1,y1,x2,y2);

   ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_3_clicked() //ddacirc
{
    int xc,yc,r;
    xc=ui->textEdit->toPlainText().toInt();
    yc=ui->textEdit_2->toPlainText().toInt();
    r=ui->textEdit_3->toPlainText().toInt();
    ddacirc(xc,yc,r);

     ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_4_clicked() //bres circ
{
    int xc,yc,r;
    xc=ui->textEdit->toPlainText().toInt();
    yc=ui->textEdit_2->toPlainText().toInt();
    r=ui->textEdit_3->toPlainText().toInt();
    brescirc(xc,yc,r);

     ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::ddaline(int x1, int y1, int x2, int y2)
{
    QRgb v;
    v=qRgb(255,255,255);
    float dx,dy;
    float xinc,yinc;
    float leng;
    float x,y;
    int i=0;

    dx=x2-x1;
    dy=y2-y1;

    if(abs(dx) >= abs(dy))
    {
        leng=abs(dx);
    }
    else
    {
        leng=abs(dy);
    }

    xinc=dx/leng;
    yinc=dy/leng;

    x=x1;
    y=y1;

    while( i <= leng)
    {
        img.setPixel(x,y,v);
        x+=xinc;
        y+=yinc;
        i++;
    }
}

void MainWindow::ddacirc(int xc, int yc, int r)
{
    QRgb v;
    v=qRgb(255,0,0);

    float x1,y1;
    float x2,y2;
    float sx,sy;

    float e;
    e=1.0/r;

    x1=r;
    y1=0;
    sx=r;
    sy=0;

    do
    {
        x2 = x1+ e*y1;
        y2 = y1 - e*x2;

        img.setPixel(xc+x2,yc-y2,v);

        x1=x2;
        y1=y2;

    }while( (y1-sy)<e  || (sx-x1)>e );
}

void MainWindow::brescirc(int xc, int yc, int r)
{
    QRgb v;
    v=qRgb(0,0,255);

    float x,y;
    float P;

    x=0;
    y=r;
    P=3-2*r;

    while(x <= y)
    {
        img.setPixel(xc+x,yc+y,v);
        img.setPixel(xc+x,yc-y,v);
        img.setPixel(xc-x,yc+y,v);
        img.setPixel(xc-x,yc-y,v);
        img.setPixel(xc+y,yc+x,v);
        img.setPixel(xc+y,yc-x,v);
        img.setPixel(xc-y,yc+x,v);
        img.setPixel(xc-y,yc-x,v);


        if(P<0)
        {
            P+=4*x+6;
        }
        else //P>0
        {
            P+=4*(x-y)+10;
            y--;
        }
        x++;
    }

}
