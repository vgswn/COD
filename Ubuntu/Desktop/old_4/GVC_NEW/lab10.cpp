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
 void neww(float* p,float* q, float* r,int cnt,float l,float m,float n)
 {
    cnt++;
    if(cnt<10)
        {

    //for(int q=0;q<10;q++){
    glColor3f(l,m,n);
    glBegin(GL_LINE_LOOP);
    glVertex2fv(p);
    glVertex2fv(q);
    glVertex2fv(r);
    glEnd();
    float x[2],y[2],z[2];
    x[0]=(p[0]+r[0])/2;
    x[1]=(p[1]+r[1])/2;
    y[0]=(q[0]+r[0])/2;
    y[1]=(q[1]+r[1])/2;
    z[0]=(p[0]+q[0])/2;
    z[1]=(p[1]+q[1])/2;


    glBegin(GL_LINE_LOOP);
    glVertex2fv(x);
    glVertex2fv(y);
    glVertex2fv(z);
    glEnd();

    //a[0]=x[0];
    //a[1]=x[1];
    //b[0]=y[0];
    //b[1]=y[1];


//}

    neww(r,x,y,cnt,l,m,n);

    neww(x,p,z,cnt,l,m,n);

    neww(y,z,q,cnt,l,m,n);
}
    else{
    }



 }
void display()
{


glClear(GL_COLOR_BUFFER_BIT);
float p[2]={-300,0};
float q[2]={300,0};
float r[2]={0,300};
int k=0;
    glColor3f(0,1,0);
    glBegin(GL_LINE_LOOP);
    glVertex2fv(p);
    glVertex2fv(q);
    glVertex2fv(r);
    glEnd();
    float x[2],y[2],z[2];
    x[0]=(p[0]+r[0])/2;
    x[1]=(p[1]+r[1])/2;
    y[0]=(q[0]+r[0])/2;
    y[1]=(q[1]+r[1])/2;
    z[0]=(p[0]+q[0])/2;
    z[1]=(p[1]+q[1])/2;


    glBegin(GL_LINE_LOOP);
    glVertex2fv(x);
    glVertex2fv(y);
    glVertex2fv(z);
    glEnd();

    neww(r,x,y,k,0.33,0.11,0.55);

    neww(x,p,z,k,0.33,0.11,0.55);


    neww(y,z,q,k, 0.79,1,0.9);






glFlush();
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("LAB10");
    init2D(0.0,0.0,0.0);
    //glutIdleFunc(idle_func);
    glutDisplayFunc(display);

    glutMainLoop();


return 0;
}

