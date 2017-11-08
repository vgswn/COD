#include<GL/glut.h>
#include<bits/stdc++.h>
#include<unistd.h>
int rot;
void init2D(float r, float g, float b)
{

glClearColor(r, g, b, 0.0);
glMatrixMode(GL_PROJECTION);

gluOrtho2D(-500, 500.0, -500.0, 500.0);
}
int a=1,b=0;
void idle_func(void)
{
unsigned int microseconds=500000;
usleep(microseconds);
 rot+=15;
glRotatef(rot, a, 0, 1.0);
 glutPostRedisplay();
 int temp=a;
 a=b;
 b=a;

 }
void display()
{


//glRotated(a,0,0,1);
glClear(GL_COLOR_BUFFER_BIT);
glTranslated(0,100,0);
glBegin(GL_LINE_LOOP);
    glVertex2d(0,50);
    glVertex2d(0,-50);
    glVertex2d(-50,0);
glEnd();
glBegin(GL_LINES);
glVertex2d(-50,50);
glVertex2d(-50,-50);
glEnd();
glBegin(GL_LINES);
glVertex2d(-100,0);
glVertex2d(50,0);
glEnd();

glTranslated(0,-100,0);
glTranslated(0,-100,0);
glBegin(GL_LINE_LOOP);
    glVertex2d(0,50);
    glVertex2d(0,-50);
    glVertex2d(-50,0);
glEnd();
glBegin(GL_LINES);
glVertex2d(-50,50);
glVertex2d(-50,-50);
glEnd();
glBegin(GL_LINES);
glVertex2d(-100,0);
glVertex2d(50,0);
glEnd();
glTranslated(0,100,0);
glTranslated(-120,0,0);
glRotated(90,0,0,1);

glBegin(GL_LINE_LOOP);
    glVertex2d(0,50);
    glVertex2d(0,-50);
    glVertex2d(-50,0);
glEnd();
glBegin(GL_LINES);
glVertex2d(-50,50);
glVertex2d(-50,-50);
glEnd();
glBegin(GL_LINES);
glVertex2d(-100,0);
glVertex2d(50,0);
glEnd();
glRotated(-90,0,0,1);
glTranslated(120,0,0);

glTranslated(120,0,0);
glRotated(90,0,0,1);

glBegin(GL_LINE_LOOP);
    glVertex2d(0,50);
    glVertex2d(0,-50);
    glVertex2d(-50,0);
glEnd();
glBegin(GL_LINES);
glVertex2d(-50,50);
glVertex2d(-50,-50);
glEnd();
glBegin(GL_LINES);
glVertex2d(-100,0);
glVertex2d(50,0);
glEnd();
glRotated(-90,0,0,1);
glTranslated(-
120,0,0);













glFlush();
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("LAB1");
    init2D(0.0,0.0,0.0);
    //glutIdleFunc(idle_func);
    glutDisplayFunc(display);

    glutMainLoop();


return 0;
}

