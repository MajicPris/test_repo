#include <iostream>
#include <glut.h>
using namespace std;

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glColor3f(0,0,1);
	glutSolidSphere(0.4, 45, 15);
	
	glFlush();
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 143);
	glutCreateWindow("Circle");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
	glutDisplayFunc(display);
	glutMainLoop();

}