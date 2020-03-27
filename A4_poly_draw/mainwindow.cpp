#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"

#include "QMouseEvent" //for mouse events
#include "QColorDialog" //for choosing color

QColor val;//globally define color choosen from dialog box
QImage img(500,500,QImage::Format_RGB888);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //always below this
    start=true; //initialize start and i value in this constructor
    i=0;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked() //get color
{
    val=QColorDialog::getColor(); //so, now color choosen is in var
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::dda(int x1, int y1, int x2, int y2)
{
    float x,y;
    float dx,dy;
    float xinc,yinc;
    float leng;

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

    int i=0;
    x=x1;
    y=y1;

    while(i<=leng)
    {
        img.setPixel(x,y,val.rgb());
        x+=xinc;
        y+=yinc;
        i++;
    }

    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    if(start)
    {
        int p=ev->pos().x(); //get x value in p
        int q=ev->pos().y(); //get y value in q

        a[i]=p; //store in the array made for x values
        b[i]=q;//store in the array made for y values


        if(ev->button()==Qt::RightButton) //check if its a RightButton
        {
            //if yes call dda n make start=false to end polygon

            dda(a[i-1],b[i-1],a[0],b[0]); //connect currentint to starting pt

            start=false;
        }
        else
        {
            if(i>0) //so i=0 case no line is drawn but only a pt will get displayed
            {
                dda(a[i-1],b[i-1],a[i],b[i]);
            }
        }

        i++;
    }

    ui->label->setPixmap(QPixmap::fromImage(img));

}


