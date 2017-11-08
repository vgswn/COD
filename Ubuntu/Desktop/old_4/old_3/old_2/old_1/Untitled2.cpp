#include<GL/glut.h>

void init2D(float r, float g, float b)
{

glClearColor(r, g, b, 0.0);
glMatrixMode(GL_PROJECTION);

gluOrtho2D(-500, 500.0, -500.0, 500.0);
}

void display()
{

glClear(GL_COLOR_BUFFER_BIT);
int a=0;int b=1;
for(int i=1;i<=1440;i++)
{
        glColor3f(a,0,b);
        glRotated(0.25,0,0,1);
        glBegin(GL_LINE_STRIP);
        glVertex2i(150,150);
        glVertex2i(200,200);
        glEnd();

        glColor3f(0,0,0);
        glBegin(GL_LINE_STRIP);
        glVertex2i(75,75);
        glVertex2i(150,150);

        glEnd();
        glColor3f(0,1,0);
        glBegin(GL_LINE_STRIP);
        glVertex2i(0,0);
        glVertex2i(75,75);

        glEnd();


        if(i%60==0)
            {
                    int temp=a;
                    a=b;
                    b=temp;
            }

}
glRotated(-360,0,0,1);
for(int i=1;i<=24;i++)
{
        glRotated(15,0,0,1);
        glColor3f(255,255,255);
        glBegin(GL_LINE_STRIP);
        glVertex2i(0,0);
        glVertex2i(150,150);

        glEnd();

}
glRotated(-360,0,0,1);

glFlush();
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("LAB1");
    init2D(1.0,1.0,1.0);
    glutDisplayFunc(display);

    glutMainLoop();


return 0;
}
