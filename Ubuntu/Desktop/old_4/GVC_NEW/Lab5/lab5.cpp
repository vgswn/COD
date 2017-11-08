


#include<GL/glut.h>
#include<bits/stdc++.h>
#include<unistd.h>
int rot;
void init2D(float r, float g, float b)
{

glClearColor(r, g, b, 0.0);
glMatrixMode(GL_PROJECTION);

gluOrtho2D(-100, 100.0, -100.0, 100.0);
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


glRotated(a,0,0,1);
glClear(GL_COLOR_BUFFER_BIT);
  GLfloat angle=(-3.14*45)/180.0;
GLfloat matrix[16]={cos(angle),sin(angle),0,0,-sin(angle),cos(angle),0,0,0,0,1,0,0,0,0,1};
GLfloat tra_matrix_orgin[16]={1,0,0,0,0,1,0,0,0,0,1,0,-20,20,0,1};
GLfloat tra_matrix_orginq[16]={1,0,0,0,0,1,0,0,0,0,1,0,20,-20,0,1};
GLfloat refl[16]={1,0,0,0,0,-1,0,0,0,0,1,0,0,0,0,1};
GLfloat shear[16]={1,2,0,0,0,1,0,0, 0,0,1,0, 0, 0, 0, 1};
//GLfloat reflection[16]={}
int a=0;int b=1;
/*for(int i=1;i<=1440;i++)

{

        glColor3f(a,0,b);
        glMultMatrixf(matrix);
        //glRotated(0.25,0,0,1);
        glBegin(GL_LINES);
        glVertex3i(150,150,0);
        glVertex3i(200,200,0);
        glEnd();

        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex3i(75,75,0);
        glVertex3i(150,150,0);

        glEnd();
        glColor3f(0,1,0);
        glBegin(GL_LINES);
        glVertex3i(0,0,0);
        glVertex3i(75,75,0);

        glEnd();


        if(i%60==0)
            {
                    int temp=a;
                    a=b;
                    b=temp;
            }

}

for(int i=1;i<=24;i++)
{
        glRotated(15,0,0,1);
        glColor3f(0,0,255);
        glBegin(GL_LINE_STRIP);
        glVertex2i(0,0);
        glVertex2i(75,75);
          glColor3f(255,255,255);
        glBegin(GL_LINE_STRIP);
        glVertex2i(75,75);
        glVertex2i(150,150);

        glEnd();

}*/


glBegin(GL_LINES);
glVertex3d(-500,0,0);
glVertex3d(500,0,0);
glEnd();
glBegin(GL_LINES);
glVertex3d(0,-500,0);
glVertex3d(0,500,0);
glEnd();

glPushMatrix();
glMultMatrixf(shear);
glMultMatrixf(tra_matrix_orgin);
glMultMatrixf(matrix);
glMultMatrixf(refl);
glBegin(GL_LINE_LOOP);

glVertex3d(-35,-5,0);
glVertex3d(-35,-35,0);
glVertex3d(-5,-35,0);
glVertex3d(-5,-5,0);


glEnd();
glMultMatrixf(tra_matrix_orginq);
glPopMatrix();



/*glPushMatrix();
glMultMatrixf(tra_matrix_orgin);
glMultMatrixf(matrix);
//glMultMatrixf(tra_matrix_orgin);

glBegin(GL_LINE_LOOP);
glVertex3d(-15,15,0);
glVertex3d(-15,-15,0);
glVertex3d(15,-15,0);
glVertex3d(15,15,0);


glEnd();
glMultMatrixf(tra_matrix_orginq);
glPopMatrix();
*/






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

