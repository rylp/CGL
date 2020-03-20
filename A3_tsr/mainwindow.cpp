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


void MainWindow::on_pushButton_clicked() //translate
{
    int x1,y1,x2,y2,tx,ty;
    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();
    tx=ui->textEdit_5->toPlainText().toInt();
    ty=ui->textEdit_6->toPlainText().toInt();
    translate(x1,y1,x2,y2,tx,ty);

    ui->label->setPixmap(QPixmap::fromImage(img));
}


void MainWindow::translate(int x1, int y1, int x2, int y2, int tx, int ty)
{
    a[0][0]=x1;
    a[0][1]=y1;
    a[0][2]=1;
    a[1][0]=x2;
    a[1][1]=y2;
    a[1][2]=1;

    t[0][0]=1;
    t[0][1]=0;
    t[0][2]=0;
    t[1][0]=0;
    t[1][1]=1;
    t[1][2]=0;
    t[2][0]=tx;
    t[2][1]=ty;
    t[2][2]=1;

    mult(a,t);

}

void MainWindow::mult(int m1[2][3], int m2[3][3])
{
    int i, j, k;

        for (i = 0; i < 2; i++)//resulting row
        {
            for (j = 0; j < 3; j++)//resulting column
            {
                c[i][j] = 0;

                for (k = 0; k < 3; k++)//common row-column
                {
                    c[i][j] = c[i][j] + (m1[i][k] * m2[k][j]);
                }
            }
        }

        bresenham(c[0][0]+200,c[0][1]+200,c[1][0]+200,c[1][1]+200);
}

void MainWindow::on_pushButton_2_clicked() //scale
{
    int x1,y1,x2,y2,sx,sy;
    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();
    sx=ui->textEdit_5->toPlainText().toInt();
    sy=ui->textEdit_6->toPlainText().toInt();
    scale(x1,y1,x2,y2,sx,sy);
    ui->label->setPixmap(QPixmap::fromImage(img));

}

void MainWindow::scale(int x1, int y1, int x2, int y2, int sx, int sy)
{
    a[0][0]=x1;
    a[0][1]=y1;
    a[0][2]=1;
    a[1][0]=x2;
    a[1][1]=y2;
    a[1][2]=1;

    s[0][0]=sx;
    s[0][1]=0;
    s[0][2]=0;
    s[1][0]=0;
    s[1][1]=sy;
    s[1][2]=0;
    s[2][0]=0;
    s[2][1]=0;
    s[2][2]=1;

    mult(a,s);

}

void MainWindow::on_pushButton_3_clicked()//rotate
{
    int x1,y1,x2,y2;
    float r,r1;
    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();
    r=ui->textEdit_7->toPlainText().toInt();
    r1 = (r*3.14)/180;
    rotate(x1,y1,x2,y2,r1);
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::rotate(int x1, int y1, int x2, int y2, float r1)
{
    float xa=0;
    float ya=0;

    a1[0][0]=x1;
    a1[0][1]=y1;
    a1[0][2]=1;
    a1[1][0]=x2;
    a1[1][1]=y2;
    a1[1][2]=1;

    r[0][0]=cos(r1);
    r[0][1]=sin(r1);
    r[0][2]=0;
    r[1][0]=-sin(r1);
    r[1][1]=cos(r1);
    r[1][2]=0;
    r[2][0]=ya*sin(r1)-xa*cos(r1)+xa;
    r[2][1]=-xa*sin(r1)-ya*cos(r1)+ya;
    r[2][2]=1;

    float_mult(a1,r);
}


void MainWindow::float_mult(float m1[2][3], float m2[3][3])
{
    int i, j, k;

        for (i = 0; i < 2; i++)//resulting row
        {
            for (j = 0; j < 3; j++)//resulting column
            {
                c1[i][j] = 0;

                for (k = 0; k < 3; k++)//common row-column
                {
                    c1[i][j] = c1[i][j] + (m1[i][k] * m2[k][j]);
                }
            }
        }

        bresenham(c1[0][0]+200,c1[0][1]+200,c1[1][0]+200,c1[1][1]+200);
}


void MainWindow::on_pushButton_4_clicked() //original
{
    int x1,y1,x2,y2;
    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();
    bresenham(x1+200,y1+200,x2+200,y2+200);

     ui->label->setPixmap(QPixmap::fromImage(img));

}

void MainWindow::on_pushButton_5_clicked() //draw
{
    bresenham(200,0,200,400);
    bresenham(0,200,400,200);

    ui->label->setPixmap(QPixmap::fromImage(img));
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
    v = qRgb(255,255,255);

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
     ui->label->setPixmap(QPixmap::fromImage(img));

}

int MainWindow::sign(int l)
{

    if(l>=0)
        return 1;
    else
        return -1;

}
