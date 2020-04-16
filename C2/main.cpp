#include<stdlib.h>
#include<GL/glut.h>
#include<fstream>
#include<iostream>
#include<math.h>
using namespace std;



float y = 10;
float y2 = 10;
float y3 = 10;
float y4 = 10;
float topy = -12;
int flag = 1;


void render(int x0,int y0,void* font,char* str){
    char* c;
    glRasterPos2f(x0,y0);
    for(c = str;*c!='\0';c++){
        glutBitmapCharacter(font,*c);
    }
}


void intro(){
    glColor3f(1,1,1);
    char buf[50] = {'0'};

    sprintf(buf,"<--TOP");
    render(3,topy,GLUT_BITMAP_TIMES_ROMAN_24,buf);

    if(flag >= 1){
        sprintf(buf,"PUSH RED");
        render(-9,9,GLUT_BITMAP_TIMES_ROMAN_24,buf);
    }
    if(flag >= 2){
        sprintf(buf,"PUSH GREEN");
        render(-9,8,GLUT_BITMAP_TIMES_ROMAN_24,buf);
    }
    if(flag >= 3){
        sprintf(buf,"PUSH BLUE");
        render(-9,7,GLUT_BITMAP_TIMES_ROMAN_24,buf);
    }
    if(flag >= 4){
        sprintf(buf,"POP BLUE");
        render(-9,6,GLUT_BITMAP_TIMES_ROMAN_24,buf);
    }
    if(flag >= 5){
        sprintf(buf,"PUSH YELLOW");
        render(-9,5,GLUT_BITMAP_TIMES_ROMAN_24,buf);
    }
    if(flag >= 6){
        sprintf(buf,"POP YELLOW");
        render(-9,4,GLUT_BITMAP_TIMES_ROMAN_24,buf);
    }
    if(flag >= 7){
        sprintf(buf,"POP GREEN");
        render(-9,3,GLUT_BITMAP_TIMES_ROMAN_24,buf);
    }
    if(flag >= 8){
        sprintf(buf,"POP RED");
        render(-9,2,GLUT_BITMAP_TIMES_ROMAN_24,buf);
    }

}




void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    intro();
    glBegin(GL_QUADS);

    glColor3f(1.0,0.0,0.0);
    glVertex2f(2,y);
    glVertex2f(-2,y);
    glVertex2f(-2,y+2);
    glVertex2f(2,y+2);

    if(flag > 1){
        glColor3f(0.0,1.0,0.0);
        glVertex2f(2,y2);
        glVertex2f(-2,y2);
        glVertex2f(-2,y2+2);
        glVertex2f(2,y2+2);
    }
    if(flag > 2 && flag <5){
        glColor3f(0.0,0.0,1.0);
        glVertex2f(2,y3);
        glVertex2f(-2,y3);
        glVertex2f(-2,y3+2);
        glVertex2f(2,y3+2);
    }

    if(flag >4){
        glColor3f(1.0,1.0,0.0);
        glVertex2f(2,y4);
        glVertex2f(-2,y4);
        glVertex2f(-2,y4+2);
        glVertex2f(2,y4+2);
    }
    glEnd();

    glutSwapBuffers();
}

void reshape(int w,int h){

//viewport
glViewport(0,0,(GLsizei)w,(GLsizei)h);	//provide coordinate for viewport

//projection
glMatrixMode(GL_PROJECTION);
glLoadIdentity();		//reset any prev matrix tranformation
gluOrtho2D(-10,10,-10,10);
glMatrixMode(GL_MODELVIEW);

}


void timer(int a){

glutPostRedisplay();
glutTimerFunc(1000/60,timer,0);

switch(flag){
        case 1: if(y>=-8)
                    y=y-0.15;
                else
                    flag=2;
                break;
        case 2: topy=-7;
                if(y2>=-5.9)
                    y2=y2-0.15;
                else
                    flag=3;
                break;
        case 3: topy=-5;
                if(y3>=-3.8)
                    y3=y3-0.15;
                else{
                    flag=4;
                    topy = -3;
                }
                break;
        case 4: topy=-5;
                if(y3<=12)
                    y3=y3+0.15;
                else{
                    topy = -5;
                    flag=5;
                }
                break;
        case 5: topy=-5;
                if(y4>=-3.8)
                    y4=y4-0.15;
                else{
                    flag=6;
                    topy = -3;
                }
                break;
        case 6: topy=-5;
                if(y4<=12)
                    y4=y4+0.15;
                else
                    flag=7;
                break;
        case 7: topy=-7;
                if(y2<=12)
                    y2=y2+0.15;
                else flag=8;
                break;
        case 8: topy = -11;
                if(y<=12)
                    y = y + 0.15;
                else flag = 1;
                break;
        }

}






int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(1000,1000);
    glutCreateWindow("STACK");

    // redraws the current window
    glutDisplayFunc(display);

    glutReshapeFunc(reshape);
    glutTimerFunc(3,timer,0);
    glutMainLoop();
}




