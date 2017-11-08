#include<GL/glut.h>
#include<stdio.h>
void init2D(float r, float g, float b)
{

glClearColor(r, g, b, 0.0);
glMatrixMode(GL_PROJECTION);

gluOrtho2D(-100, 100.0, -100.0, 100.0);
}
void multiply(float first[3][3],float second[3],float pqr[3] )
{

	int s=0;
	int k=0;
	for(int i=0;i<3;i++){
	for(int j=0;j<3;j++)
	{
		s=s+first[i][j]*second[j];
	}
	pqr[k++]=s;
	s=0;
}

}

void display()
{

glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1,0,0);

	float trans1[3][3]={
		{1,0,20},
		{0,1,-5},
		{0,0,1}
	};
	float rotatet[3][3]={{0.87,-0.87,0},{0.87,0.87,0},{0,0,1}};
	float sher[3][3]={{1,1,0},{0,1,0},{0,0,1}};

	float trans2[3][3]={{1,0,-20},{0,1,5},{0,0,1}};
	float reflect[3][3]={{1,0,0},{0,-1,0},{0,0,1}};
	float trans3[3][3]={{1,0,-20},{0,1,5},{0,0,1}};

	float xyz[4][3]={{-35,-5,1},{-5,-5,1},{-35,-35,1},{-5,-35,1}};
	glBegin(GL_LINES);
	glVertex2d(-100,0);
	glVertex2d(100,0);
	glEnd();
    glBegin(GL_LINES);
	glVertex2d(0,-100);
	glVertex2d(0,100);
	glEnd();

	/*glBegin(GL_LINE_STRIP);
	glVertex3f(xyz[0][0],xyz[0][1],xyz[0][2]);
	glVertex3f(xyz[1][0],xyz[1][1],xyz[1][2]);
	glVertex3f(xyz[3][0],xyz[3][1],xyz[3][2]);
	glVertex3f(xyz[2][0],xyz[2][1],xyz[2][2]);
	glVertex3f(xyz[0][0],xyz[0][1],xyz[0][2]);
glEnd();*/
	float pqr[4][3];
	multiply(reflect,xyz[0],pqr[0]);
	multiply(reflect,xyz[1],pqr[1]);
	multiply(reflect,xyz[2],pqr[2]);
	multiply(reflect,xyz[3],pqr[3]);

		/*glBegin(GL_LINE_STRIP);
	glVertex3f(pqr[0][0],pqr[0][1],0);
	glVertex3f(pqr[1][0],pqr[1][1],0);
	glVertex3f(pqr[3][0],pqr[3][1],0);
	glVertex3f(pqr[2][0],pqr[2][1],0);
	glVertex3f(pqr[0][0],pqr[0][1],0);
glEnd();*/
float pqr1[4][3];
	multiply(trans1,pqr[0],pqr1[0]);
	multiply(trans1,pqr[1],pqr1[1]);
	multiply(trans1,pqr[2],pqr1[2]);
	multiply(trans1,pqr[3],pqr1[3]);

    /*glBegin(GL_LINE_STRIP);
	glVertex3f(pqr1[0][0],pqr1[0][1],0);
	glVertex3f(pqr1[1][0],pqr1[1][1],0);
	glVertex3f(pqr1[3][0],pqr1[3][1],0);
	glVertex3f(pqr1[2][0],pqr1[2][1],0);
	glVertex3f(pqr1[0][0],pqr1[0][1],0);
glEnd();
*/

float pqr2[4][3];

multiply(sher,pqr1[0],pqr1[0]);
	multiply(sher,pqr1[1],pqr2[1]);
	multiply(sher,pqr1[2],pqr2[2]);
	multiply(sher,pqr1[3],pqr2[3]);

		glBegin(GL_LINE_STRIP);
	glVertex3f(pqr2[0][0],pqr2[0][1],0);
	glVertex3f(pqr2[1][0],pqr2[1][1],0);
	glVertex3f(pqr2[3][0],pqr2[3][1],0);
	glVertex3f(pqr2[2][0],pqr2[2][1],0);
	glVertex3f(pqr2[0][0],pqr2[0][1],0);
glEnd();




/*float pqr3[4][3];

multiply(rotatet,pqr2[0],pqr3[0]);
	multiply(rotatet,pqr2[1],pqr3[1]);
	multiply(rotatet,pqr2[2],pqr3[2]);
	multiply(rotatet,pqr2[3],pqr3[3]);

		glBegin(GL_LINE_STRIP);
	glVertex3f(pqr3[0][0],pqr3[0][1],0);
	glVertex3f(pqr3[1][0],pqr3[1][1],0);
	glVertex3f(pqr3[3][0],pqr3[3][1],0);
	glVertex3f(pqr3[2][0],pqr3[2][1],0);
	glVertex3f(pqr3[0][0],pqr3[0][1],0);
glEnd();


*/


float pqr4[4][3];

/*multiply(trans1,pqr3[0],pqr4[0]);
	multiply(trans1,pqr3[1],pqr4[1]);
	multiply(trans1,pqr3[2],pqr4[2]);
	multiply(trans1,pqr3[3],pqr4[3]);

		glBegin(GL_LINE_STRIP);
	glVertex3f(pqr4[0][0],pqr4[0][1],0);
	glVertex3f(pqr4[1][0],pqr4[1][1],0);
	glVertex3f(pqr4[3][0],pqr4[3][1],0);
	glVertex3f(pqr4[2][0],pqr4[2][1],0);
	glVertex3f(pqr4[0][0],pqr4[0][1],0);
glEnd();


*/


multiply(trans3,pqr2[0],pqr4[0]);
	multiply(trans3,pqr2[1],pqr4[1]);
	multiply(trans3,pqr2[2],pqr4[2]);
	multiply(trans3,pqr2[3],pqr4[3]);

		glBegin(GL_LINE_STRIP);
	glVertex3f(pqr4[0][0],pqr4[0][1],0);
	glVertex3f(pqr4[1][0],pqr4[1][1],0);
	glVertex3f(pqr4[3][0],pqr4[3][1],0);
	glVertex3f(pqr4[2][0],pqr4[2][1],0);
	glVertex3f(pqr4[0][0],pqr4[0][1],0);
glEnd();













glFlush();
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("LAB5");
    init2D(1.0,1.0,1.0);
    glutDisplayFunc(display);

    glutMainLoop();


return 0;
}

