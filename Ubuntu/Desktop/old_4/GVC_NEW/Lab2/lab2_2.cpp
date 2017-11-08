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

    for(int i=0;i<36;i++){
    glRotated(10,0,0,1);
    glBegin(GL_LINE_LOOP);
    glVertex2d(0,0);
    glVertex2d(-100,100);
    glVertex2d(0,100);
    glVertex2d(100,100);
    glEnd();




}
//glRotated(-360,0,0,1);
glBegin(GL_LINES);
glVertex2d(0,0);
glVertex2d(0,-400);
glEnd();
glBegin(GL_TRIANGLES);
glVertex2d(0,-370);
glVertex2d(-20,-370);
glVertex2d(0,-400);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2d(0,-370);
glVertex2d(20,-370);
glVertex2d(0,-400);
glEnd();



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

