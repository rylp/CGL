#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMouseEvent"
using namespace std;
QImage img(400,400,QImage::Format_RGB888);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    inside=0;
    left=1;
    right=2;
    bottom=4;
    top=8;

    i=0;
    start=true;
    xmin=50,xmax=200,ymin=50,ymax=200;
}

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    if(start)
     {
         int p=ev->pos().x();
         int q=ev->pos().y();
         a[i]=p;
         b[i]=q;
         if(ev->button() == Qt::RightButton)
         {
             DDA(a[i],b[i],a[0],b[0]);
             start=false;
         }
         else
         {
             if(i>0 && i%2 != 0)
             {
                 DDA(a[i],b[i],a[i-1],b[i-1]);
             }
         }
         i++;
     }
}


void MainWindow::on_pushButton_clicked() //draw
{
    DDA(50,50,50,200);
    DDA(50,200,200,200);
    DDA(200,200,200,50);
    DDA(200,50,50,50);

     ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_2_clicked() //clear
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

void MainWindow::on_pushButton_3_clicked() //clip
{
    int count=0;
    while(count != i)
    {
        cohen(a[count],b[count],a[count+1],b[count+1]);
        count=count+2;
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::cohen(int x1, int y1, int x2, int y2)
{
    int code1,code2;
    code1=compute(x1,y1);
    code2=compute(x2,y2);
    bool accept=false;
    int x,y;

    while(1)
    {
        if(code1==0&&code2==0)
        {
            accept=true;
            break;
        }
        else if(code1&code2)
            break;
        else
        {
            int code3;
            if(code1!=0)
                code3=code1;
            else
                code3=code2;
            if(code3&top)
            {
                x=x1+(x2-x1)*(ymin-y1)/(y2-y1);
                y=ymin;
            }
            if(code3&bottom)
            {
                x=x1+(x2-x1)*(ymax-y1)/(y2-y1);
                y=ymax;
            }
            if(code3&left)
            {
                x=xmin;
                y=y1+(y2-y1)*(xmin-x1)/(x2-x1);
            }
            if(code3&right)
            {
                x=xmax;
                y=y1+(y2-y1)*(xmax-x1)/(x2-x1);
            }

            if(code3==code1)
            {
                x1=x;
                y1=y;
                code1=compute(x1,y1);
            }
            else
            {
                x2=x;
                y2=y;
                code2=compute(x2,y2);
            }
        }
    }
   if(accept==true)
       DDA(x1,y1,x2,y2);

}

int MainWindow::compute(int x, int y)
{
    int code=inside;
       if(x<xmin)
               code|=left;
       if(x>xmax)
               code|=right;
       if(y>ymax)
               code|=bottom;
       if(y<ymin)
               code|=top;
       return code;
}

void MainWindow::DDA(int x1, int y1, int x2, int y2)
{
     float dx,dy;
     dx=x2-x1;
     dy=y2-y1;
     float len;
     if(abs(x2-x1) >= abs(y2-y1))
     {
         len=abs(x2-x1);
     }
     else
     {
         len=abs(y2-y1);
     }
     float xinc,yinc;
     xinc=dx/len;
     yinc=dy/len;
     float x=x1;
     float y=y1;
     int j=0;
     while(j<=len)
     {
         img.setPixel(x,y,qRgb(0,255,0));
         x=x+xinc;
         y=y+yinc;
         j++;
     }
     ui->label->setPixmap(QPixmap::fromImage(img));

}

MainWindow::~MainWindow()
{
    delete ui;
}
