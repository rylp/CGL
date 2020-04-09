#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"
#include "QMouseEvent"

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


void MainWindow::on_pushButton_clicked()//draw
{
    bresenham(100,100,300,100);
    bresenham(300,100,300,300);
    bresenham(300,300,100,300);
    bresenham(100,300,100,100);

    bresenham(150,100,150,300);
    bresenham(200,100,200,300);
    bresenham(250,100,250,300);

    bresenham(100,150,300,150);
    bresenham(100,200,300,200);
    bresenham(100,250,300,250);
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_2_clicked()//clear
{
    for(int m=0;m<399;m++)
    {
       for(int n=0;n<399;n++)
       {
            img.setPixel(m,n,qRgb(0,0,0));
       }
    }


     ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_3_clicked()//rotate
{
    arbitrary(100,100,300,100);
    arbitrary(300,100,300,300);
    arbitrary(300,300,100,300);
    arbitrary(100,300,100,100);

    arbitrary(150,100,150,300);
    arbitrary(200,100,200,300);
    arbitrary(250,100,250,300);

    arbitrary(100,150,300,150);
    arbitrary(100,200,300,200);
    arbitrary(100,250,300,250);

    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::bresenham(int x1, int y1, int x2, int y2)
{
    float dx,dy;
    float x,y;
    float leng;
    float P;

    QRgb v;
    v=qRgb(255,255,255);

    dx=abs(x2-x1);
    dy=abs(y2-y1);

    x=x1;
    y=y1;

    if(dx>=dy)//m<1 x always inc check for y
    {
        leng=dx;
        P=2*dy-dx;
        int i=0;

        while(i<=leng)
        {
            img.setPixel(x,y,v);
            if(P<0)
            {
                P+=2*dy;
            }
            else
            {
                P+=2*(dy-dx);
                y+= 1*sign(y2-y1);
            }

            x+=1*sign(x2-x1);
            i++;
        }
    }

    else //m>1 y always inc, check for x
    {
        leng=dy;
        P=2*dx-dy;
        int i=0;

        while(i<=leng)
        {
            img.setPixel(x,y,v);
            if(P<0)
            {
                P+=2*dx;
            }
            else
            {
                P+=2*(dx-dy);
                x+= 1*sign(x2-x1);
            }

            y+=1*sign(y2-y1);
            i++;
        }

    }

     ui->label->setPixmap(QPixmap::fromImage(img));

}

int MainWindow::sign(int l)
{
    if(l>=0)
    {
        return 1;
    }
    return -1;

    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *ev)
{
    int p=ev->pos().x();
    int q=ev->pos().y();

    QRgb bg;
    bg=qRgb(0,0,0);

    seedfill(p,q,bg);

    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::seedfill(int x, int y, QRgb bg)
{
    QRgb v;
    v=qRgb(255,255,255);//white color

    while(img.pixel(x,y)==bg)
    {
        img.setPixel(x,y,v);

        seedfill(x+1,y,bg);
        seedfill(x-1,y,bg);
        seedfill(x,y+1,bg);
        seedfill(x,y-1,bg);

    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::arbitrary(int x1, int y1, int x2, int y2)
{
    float theta=45*3.14/360;
    int xa=200;
    int ya=200;

    a[0][0]=x1;
    a[0][1]=y1;
    a[0][2]=1;
    a[1][0]=x2;
    a[1][1]=y2;
    a[1][2]=1;

    r[0][0]=cos(theta);
    r[0][1]=sin(theta);
    r[0][2]=0;
    r[1][0]=-sin(theta);
    r[1][1]=cos(theta);
    r[1][2]=0;
    r[2][0]=ya*sin(theta)-xa*cos(theta)+xa;
    r[2][1]=-xa*sin(theta)-ya*cos(theta)+ya;
    r[2][2]=1;

    float_mult(a,r);

    ui->label->setPixmap(QPixmap::fromImage(img));

}

void MainWindow::float_mult(float a[2][3], float b[3][3])
{
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            c[i][j]=0;

            for(int k=0;k<3;k++)
            {
                c[i][j]= c[i][j]+ (a[i][k]*b[k][j]);
            }
        }
    }

    bresenham(c[0][0],c[0][1],c[1][0],c[1][1]);

    ui->label->setPixmap(QPixmap::fromImage(img));
}



