#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"

QImage img(500,500,QImage::Format_RGB888);

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


void MainWindow::on_pushButton_clicked()//solid
{
    int x1,y1,x2,y2;

    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();

    solid(x1,y1,x2,y2);

    ui->label->setPixmap(QPixmap::fromImage(img));

}


void MainWindow::solid(int x1, int y1, int x2, int y2)
{
    float dx,dy;
    float x,y;
    float xinc,yinc;
    float leng;
    int i;

    QRgb v;
    v=qRgb(0,255,0);


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

    i=0;

    x=x1;
    y=y1;

    while(i<=leng)
    {
        img.setPixel(x,y,v);
        x+=xinc;
        y+=yinc;
        i++;
    }

      ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_2_clicked()//dotted
{
    int x1,y1,x2,y2;

    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();

    dotted(x1,y1,x2,y2);

    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::dotted(int x1, int y1, int x2, int y2)
{
    float dx,dy;
    float x,y;
    float xinc,yinc;
    float leng;
    int i;

    QRgb v;
    v=qRgb(0,255,0);


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

    i=0;

    x=x1;
    y=y1;

    while(i<=leng)
    {
        //condition for dotted
        if(i%4==0)
        {
            img.setPixel(x,y,v);
        }

        x+=xinc;
        y+=yinc;
        i++;
    }

      ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_3_clicked()//dashed
{
    int x1,y1,x2,y2;

    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();

    dashed(x1,y1,x2,y2);

    ui->label->setPixmap(QPixmap::fromImage(img));

}

void MainWindow::dashed(int x1, int y1, int x2, int y2)
{
    float dx,dy;
    float x,y;
    float xinc,yinc;
    float leng;
    int i;

    QRgb v;
    v=qRgb(0,255,0);


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

    i=0;

    x=x1;
    y=y1;

    while(i<=leng)
    {
        if(i%6!=0)//condition for dotted
        {
            img.setPixel(x,y,v);
        }

        x+=xinc;
        y+=yinc;
        i++;
    }

      ui->label->setPixmap(QPixmap::fromImage(img));
}


void MainWindow::on_pushButton_4_clicked()//dash-dot
{
    int x1,y1,x2,y2;

    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();

    dashdot(x1,y1,x2,y2);

    ui->label->setPixmap(QPixmap::fromImage(img));

}

void MainWindow::dashdot(int x1, int y1, int x2, int y2)
{
    float dx,dy;
    float x,y;
    float xinc,yinc;
    float leng;
    int i;

    QRgb v;
    v=qRgb(0,255,0);


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

    i=0;

    x=x1;
    y=y1;

    while(i<=leng)
    {
        //in every set of 10, first 5 will be printed(dashed) n then 7th will be printed(dotted)
        if(i%10 < 5)//dashed
        {
            img.setPixel(x,y,v);
        }

        if(i%10==7) //dotted
        {
             img.setPixel(x,y,v);
        }

        x+=xinc;
        y+=yinc;
        i++;
    }

      ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_5_clicked()//thick
{
    int x1,y1,x2,y2;

    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();

    thick(x1,y1,x2,y2);

    ui->label->setPixmap(QPixmap::fromImage(img));

}

void MainWindow::thick(int x1, int y1, int x2, int y2)
{
    float dx,dy;
    float x,y;
    float xinc,yinc;
    float leng;
    int i;
    int w;

    QRgb v;
    v=qRgb(0,255,0);


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

    i=0;
    x=x1;
    y=y1;
    w=4;

    while(i<=leng)
    {
        //check greater value and then for loop from i=-w/2 , i <w/2 , i++
        if(abs(dx)>abs(dy))
        {
            for(int i=-w/2; i<w/2;i++)
            {
                //as dx > dy case, keep x as it is and add in y ie y+i
                img.setPixel(x,y+i,v);
            }

        }

        else // abs(dy)>abs(dx)
        {
            for(int i=-w/2;i<w/2;i++)
            {
                //as dy > dx case, keep y as it is and add in x ie x+i
                img.setPixel(x+i,y,v);
            }

        }

        x+=xinc;
        y+=yinc;
        i++;
    }

      ui->label->setPixmap(QPixmap::fromImage(img));
}
