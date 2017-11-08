

#include <GL/glut.h>
 GLfloat xRotated, yRotated, zRotated;

void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   glClearDepth(1.0f);                   // Set background depth to farthest
   glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
   glDepthFunc(GL_LEQUAL);
}
void display() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3d(1,0,0);
	glMatrixMode(GL_MODELVIEW);
	glOrtho(-100,100,-100,100,0,100);
	glLoadIdentity();
	 float tri[3][3]={{0,0,0},{1.0,0,0},{0.5,0.86602,0}};
	 glTranslatef(0.5f, -0.5f, -6.0f);
	 gluLookAt(0,5,0,0,0,0,0,0,1);
   glRotatef(xRotated,1.0,0.0,0.0);
    glRotatef(yRotated,0.0,1.0,0.0);
    glRotatef(zRotated,0.0,0.0,1.0);





	 glTranslated(0,0,0);
	 glRotated(-35,1,0,0);
    glColor3d(1,0,0);
    glBegin(GL_POLYGON);
    glVertex2fv(tri[0]);
    glVertex2fv(tri[1]);
    glVertex2fv(tri[2]);
    glEnd();
    glRotated(35,1,0,0);

    glRotated(90,0,1,0);

    glRotated(35,1,0,0);
        glColor3d(0,1,0);

        glBegin(GL_POLYGON);
    glVertex2fv(tri[0]);
    glVertex2fv(tri[1]);
    glVertex2fv(tri[2]);
    glEnd();
    glRotated(-35,1,0,0);


    glTranslated(0,0,1);
    glRotated(-35,1,0,0);
        glColor3d(0,0,1);

    glBegin(GL_POLYGON);
    glVertex2fv(tri[0]);
    glVertex2fv(tri[1]);
    glVertex2fv(tri[2]);
    glEnd();
    glRotated(35,1,0,0);
    glTranslated(0,0,-1);



    glRotated(-90,0,1,0);
    glTranslated(0,0,-1);
    glRotated(35,1,0,0);
        glColor3d(1,0,1);

        glBegin(GL_POLYGON);
    glVertex2fv(tri[0]);
    glVertex2fv(tri[1]);
    glVertex2fv(tri[2]);
    glEnd();
   glRotated(-35,1,0,0);
    glTranslated(0,0,1);


   // glTranslated(-1,0.86,-2);
/*glColor3d(1,1,0.5);
    glBegin(GL_POLYGON);
    glVertex3d(0,0,0);
    glVertex3d(0,0,-1);
    glVertex3d(1,0,-1);
    glVertex3d(1,0,0);

    glEnd();*/








glFlush();


	glutSwapBuffers();
}
void animation(void)
{

     yRotated += 0.10;
     xRotated += 0.10;
     zRotated+=0.10;
    display();
}

void reshape(int x, int y)
{
    if (y == 0 || x == 0) return;  //Nothing is visible then, so return
    //Set a new projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //Angle of view:40 degrees
    //Near clipping plane distance: 0.5
    //Far clipping plane distance: 20.0

    gluPerspective(40.0,(GLdouble)x/(GLdouble)y,0.5,20.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,x,y);  //Use the whole window for rendering
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(400, 200);
	glutCreateWindow("lab8");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
glutIdleFunc(animation);
initGL();

	glutMainLoop();
	return 0;
}

