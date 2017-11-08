
#include <GL/glut.h>

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3d(1,0,0);
	glMatrixMode(GL_MODELVIEW);
	glOrtho(-100,100,-100,100,0,100);
	glLoadIdentity();
	 float tri[3][3]={{0,0,0},{1.0,0,0},{0.5,0.86602,0}};
	 glTranslatef(0.5f, -0.5f, -6.0f);
	 glTranslated(-2.0,0,0);

    for(int i=0;i<4;i++){
       glRotated(90,1,0,0);
        glBegin(GL_LINE_LOOP);
        glVertex3fv(tri[0]);
        glVertex3fv(tri[1]);
        glVertex3fv(tri[2]);
        glEnd();
        glRotated(-90,1,0,0);
        glRotated(90,0,0,1);
        glTranslated(-1.0,0,0);
    }
    glTranslated(2.0,0,0);
	 glRotated(-90,1,0,0);
    for(int i=0;i<4;i++){
        glRotated(90,1,0,0);
        glBegin(GL_LINE_LOOP);
        glVertex3fv(tri[0]);
        glVertex3fv(tri[1]);
        glVertex3fv(tri[2]);
        glEnd();
        glRotated(-90,1,0,0);
        glRotated(90,0,0,1);
        glTranslated(-1.0,0,0);
    }
	glutSwapBuffers();
}

void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
	// Compute aspect ratio of the new window
	if (height == 0) height = 1;
	GLfloat aspect = (GLfloat)width / (GLfloat)height;
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
	glLoadIdentity();
	// Enable perspective projection with fovy, aspect, zNear and zFar
	gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
	glutInit(&argc, argv);            // Initialize GLUT
	glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
	glutInitWindowSize(640, 480);   // Set the window's initial width & height
	glutInitWindowPosition(400, 200); // Position the window's initial top-left corner
	glutCreateWindow("lab8");          // Create window with the given title
	glutDisplayFunc(display);       // Register callback handler for window re-paint event
	glutReshapeFunc(reshape);       // Register callback handler for window re-size event

	glutMainLoop();                 // Enter the infinite event-processing loop
	return 0;
}
