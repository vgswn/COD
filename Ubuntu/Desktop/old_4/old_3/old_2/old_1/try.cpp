#include<GL/glut.h>
GLfloat win_left = -500;
GLfloat win_right = 500;
GLfloat win_bottom = -500;
GLfloat win_top = 500;
void init2D(float r, float g, float b)
{

glClearColor(r, g, b, 0.0);
glMatrixMode(GL_PROJECTION);

gluOrtho2D(-100, 100.0, -100.0, 100.0);
}
float* multiply(float first[3][3],float second[3] )
{
	float ans[3];
	int s=0;
	int k=0;
	for(int j=0;j<3;j++){
	for(int i=0;i<3;i++)
	{
		s=s+first[j][i]+second[i];
	}
	ans[k++]=s;
	s=0;
}
return ans;

}
void display()
{

glClear(GL_COLOR_BUFFER_BIT);
	
	float trans1[3][3]={
		{1,0,0},
		{0,1,0},
		{0,0,1}
	};
	float rotate[3][3]={{0.87,-0.87,0},{0.87,0.87,0},{0,0,1}};
	float sher[3][3]={{1,2,0},{0,1,0},{0,0,1}};

	float trans2[3][3]={{1,0,-2},{0,1,-2},{0,0,1}};
	float reflect[3][3]={{1,0,0},{0,-1,0},{0,0,1}};

	float xyz[4][3]={{-35,-5,1},{-5,-5,1},{-35,-35,1},{-5,-35,1}};

	glBegin(GL_LINE_STRIP);
	glVertex3f(xyz[0][0],xyz[0][1],xyz[0][2]);
	glVertex3f(xyz[1][0],xyz[1][1],xyz[1][2]);
	glVertex3f(xyz[2][0],xyz[2][1],xyz[2][2]);
	glVertex3f(xyz[3][0],xyz[3][1],xyz[3][2]);
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

