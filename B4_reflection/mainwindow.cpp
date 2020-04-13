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


void MainWindow::on_pushButton_clicked()//reflecton X
{
    float x1,y1,x2,y2;
    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();
    reflectionX(x1,y1,x2,y2);

    ui->label->setPixmap(QPixmap::fromImage(img));

}

void MainWindow::on_pushButton_2_clicked()//reflection y
{
    float x1,y1,x2,y2;
    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();
    reflectionY(x1,y1,x2,y2);

    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_3_clicked()//reflection xy
{
    float x1,y1,x2,y2;
    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();
    reflectionXY(x1,y1,x2,y2);

    ui->label->setPixmap(QPixmap::fromImage(img));

}

void MainWindow::on_pushButton_4_clicked()//arbitrary
{
    float x1,y1,x2,y2,xa,ya,r1;
    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();
    xa=ui->textEdit_5->toPlainText().toInt();
    ya=ui->textEdit_6->toPlainText().toInt();
    r1=ui->textEdit_7->toPlainText().toInt();
    float r=r1*3.14/180;
    arbitrary(x1,y1,x2,y2,xa,ya,r);

    ui->label->setPixmap(QPixmap::fromImage(img));

}

void MainWindow::on_pushButton_5_clicked()//draw
{
    bresenham(200,0,200,400);
    bresenham(0,200,400,200);
    ui->label->setPixmap(QPixmap::fromImage(img));

}

void MainWindow::on_pushButton_6_clicked()//original
{
    float x1,y1,x2,y2;
    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();
    bresenham(x1+200,y1+200,x2+200,y2+200);
    ui->label->setPixmap(QPixmap::fromImage(img));

}

void MainWindow::reflectionX(float x1, float y1, float x2, float y2)
{
    a[0][0]=x1;
    a[0][1]=y1;
    a[0][2]=1;
    a[1][0]=x2;
    a[1][1]=y2;
    a[1][2]=1;

    rx[0][0]=1;
    rx[0][1]=0;
    rx[0][2]=0;
    rx[1][0]=0;
    rx[1][1]=-1;
    rx[1][2]=0;
    rx[2][0]=0;
    rx[2][1]=0;
    rx[2][2]=1;

    float_mult(a,rx);

      ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::reflectionY(float x1, float y1, float x2, float y2)
{
    a[0][0]=x1;
    a[0][1]=y1;
    a[0][2]=1;
    a[1][0]=x2;
    a[1][1]=y2;
    a[1][2]=1;

    ry[0][0]=-1;
    ry[0][1]=0;
    ry[0][2]=0;
    ry[1][0]=0;
    ry[1][1]=1;
    ry[1][2]=0;
    ry[2][0]=0;
    ry[2][1]=0;
    ry[2][2]=1;

    float_mult(a,ry);

      ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::reflectionXY(float x1, float y1, float x2, float y2)
{
    a[0][0]=x1;
    a[0][1]=y1;
    a[0][2]=1;
    a[1][0]=x2;
    a[1][1]=y2;
    a[1][2]=1;

    rxy[0][0]=-1;
    rxy[0][1]=0;
    rxy[0][2]=0;
    rxy[1][0]=0;
    rxy[1][1]=-1;
    rxy[1][2]=0;
    rxy[2][0]=0;
    rxy[2][1]=0;
    rxy[2][2]=1;

    float_mult(a,rxy);

    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::arbitrary(float x1, float y1, float x2, float y2, float xa, float ya, float r)
{
    a[0][0]=x1;
    a[0][1]=y1;
    a[0][2]=1;
    a[1][0]=x2;
    a[1][1]=y2;
    a[1][2]=1;

    arb[0][0]=cos(r);
    arb[0][1]=sin(r);
    arb[0][2]=0;
    arb[1][0]=-1*sin(r);
    arb[1][1]=cos(r);
    arb[1][2]=0;
    arb[2][0]=ya*sin(r)-xa*cos(r)+xa;
    arb[2][1]=-1*xa*sin(r)-ya*cos(r)+ya;
    arb[2][2]=1;

    float_mult(a,arb);

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
                c[i][j]+=(a[i][k]*b[k][j]);
            }
        }
    }

    bresenham(c[0][0]+200,c[0][1]+200,c[1][0]+200,c[1][1]+200);

 ui->label->setPixmap(QPixmap::fromImage(img));

}

void MainWindow::bresenham(float x1, float y1, float x2, float y2)
{
    float x,y;
    float dx,dy;
    float leng;
    float P;

    QRgb v;
    v=qRgb(255,255,255);

    dx=abs(x2-x1);
    dy=abs(y2-y1);

    x=x1;
    y=y1;

    if(dx>=dy)//m<1 , x always inc, check for y
    {
        leng=dx;
        int i=0;
        P=2*dy-dx;

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
                y+=1*sign(y2-y1);
            }

            x+=1*sign(x2-x1);
            i++;
        }
    }
    else
    {
        leng=dy;
        int i=0;
        P=2*dx-dy;

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
                x+=1*sign(x2-x1);
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
