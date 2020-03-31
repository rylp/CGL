#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMouseEvent"
#include "QColorDialog"
#include "math.h"

QColor val;

QImage img(400,400,QImage::Format_RGB888);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //below always
    i=0;
    start=true;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked() //getcolor
{
    val = QColorDialog::getColor();

    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::bresenham(int x1, int y1, int x2, int y2)
{
    float dx,dy;
    float leng;
    float x,y;
    float P;

    dx=abs(x2-x1);
    dy=abs(y2-y1);

    QRgb v;
    v=qRgb(255,255,255);

    x=x1;
    y=y1;

    if(dx>=dy) // m < 1 , x always inc , check y
    {
        P= 2*dy - dx;
        int i=0;
        leng=dx;

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
                y = y + 1*sign(y2-y1);

            }

            x = x+ 1*sign(x2-x1);
            i++;

        }
    }

    else // dy > dx ie  m>1 ie y always inc , check for x
    {
        P=2*dx - dy;
        int j=0;
        leng=dy;

        while( j <= leng)
        {
            img.setPixel(x,y,v);

            if(P<0)
            {
                P+=2*dx;
            }

            else
            {
                P+=2*(dx-dy);
                x = x+ 1*sign(x2-x1);
            }

            y = y + 1*sign(y2-y1);
            j++;
        }
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

int MainWindow::sign(int l)
{
    if(l >= 1)
    {
        return 1;
    }

    return -1;
}

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    if(start)
    {
        int p=ev->pos().x(); //get curr x-coordinate
        int q=ev->pos().y(); //get curr y coordinate

        a[i]=p; //store in array storing x coordinate of all pts
        b[i]=q; //store in array storing x coordinate of all pts

        if(ev->button()==Qt::RightButton)
        {
            //if rightbutton , call curr point to starting point n make start=false
            bresenham(a[i-1],b[i-1],a[0],b[0]);
            start=false;
        }

        else
        {
            if(i>0) //to avois situation of first line drawn
            {
                bresenham(a[i-1],b[i-1],a[i],b[i]);
            }
        }
        i++;
    }

    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *ev)
{
    QRgb bg; //set bg to black
    bg=qRgb(0,0,0);

    int p=ev->pos().x(); //get x co-or
    int q=ev->pos().y(); //get y co-or

    seedfill(p,q,bg);

    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::seedfill(int x, int y, QRgb bg)
{
    //floodfill algorithm

    if(img.pixel(x,y)==bg) //if color matches with black, then only seedfill
    {
        img.setPixel(x,y,val.rgb()); //give val.rgb()

        //call recursively
        seedfill(x+1,y,bg);
        seedfill(x-1,y,bg);
        seedfill(x,y+1,bg);
        seedfill(x,y-1,bg);
    }

    ui->label->setPixmap(QPixmap::fromImage(img));
}



