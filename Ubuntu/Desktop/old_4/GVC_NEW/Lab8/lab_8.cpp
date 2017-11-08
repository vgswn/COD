

#include <GL/glut.h>

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3d(1,0,0);
	glMatrixMode(GL_MODELVIEW);
	glOrtho(-100,100,-100,100,0,100);
	glLoadIdentity();
	 float tri[3][3]={{0,0,0},{1.0,0,0},{0.5,0.86602,0}};
	 glTranslatef(0.5f, -0.5f, -6.0f);
    //gluLookAt(0,-5,0,0,0,0,0,0,1);

	 glTranslated(0,0,0);
	 glRotated(-35,1,0,0);

    glBegin(GL_LINE_LOOP);
    glVertex2fv(tri[0]);
    glVertex2fv(tri[1]);
    glVertex2fv(tri[2]);
    glEnd();
    glRotated(35,1,0,0);

    glRotated(90,0,1,0);

    glRotated(35,1,0,0);
        glBegin(GL_LINE_LOOP);
    glVertex2fv(tri[0]);
    glVertex2fv(tri[1]);
    glVertex2fv(tri[2]);
    glEnd();
    glRotated(-35,1,0,0);


    glTranslated(0,0,1);
    glRotated(-35,1,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex2fv(tri[0]);
    glVertex2fv(tri[1]);
    glVertex2fv(tri[2]);
    glEnd();
    glRotated(35,1,0,0);
    glTranslated(0,0,-1);



    glRotated(-90,0,1,0);
    glTranslated(0,0,-1);
    glRotated(35,1,0,0);
        glBegin(GL_LINE_LOOP);
    glVertex2fv(tri[0]);
    glVertex2fv(tri[1]);
    glVertex2fv(tri[2]);
    glEnd();
   glRotated(-35,1,0,0);
    glTranslated(0,0,1);

    //glRotated(-90,1,0,0);
    glTranslated(-1.9,1,0);
    glBegin(GL_LINE_LOOP);
    glVertex2fv(tri[0]);
    glVertex2fv(tri[1]);
    glVertex2fv(tri[2]);
    glEnd();

   glTranslated(0,-1,0);
    glRotated(180,1,0,0);
        glBegin(GL_LINE_LOOP);
    glVertex2fv(tri[0]);
    glVertex2fv(tri[1]);
    glVertex2fv(tri[2]);
    glEnd();
    glRotated(-180,1,0,0);
    glTranslated(0,1,0);
    glRotated(180,1,0,0);
    glRotated(90,0,0,1);

        glBegin(GL_LINE_LOOP);
    glVertex2fv(tri[0]);
    glVertex2fv(tri[1]);
    glVertex2fv(tri[2]);
    glEnd();
       glRotated(-90,0,0,1);
        glRotated(-180,1,0,0);


            glRotated(-180,1,0,0);
            glTranslated(1,0,0);
        glRotated(90,0,0,1);
         glRotated(-180,1,0,0);

        glBegin(GL_LINE_LOOP);
    glVertex2fv(tri[0]);
    glVertex2fv(tri[1]);
    glVertex2fv(tri[2]);
    glEnd();











	glutSwapBuffers();
}

void reshape(GLsizei width, GLsizei height) {
	if (height == 0) height = 1;
	GLfloat aspect = (GLfloat)width / (GLfloat)height;
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(400, 200);
	glutCreateWindow("lab8");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	glutMainLoop();
	return 0;
}
