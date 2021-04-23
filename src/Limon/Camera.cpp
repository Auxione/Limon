#include "Camera.h"
#include "GLFW/glfw3.h"

void limon::Camera::ScreenToWorld(double& posx, double& posy) {
	posx -= position.x;
	posy -= position.y;
}

void limon::Camera::Begin() {
	glViewport(0, 0, size.x, size.y);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glScalef(scale, scale, 1);
	glOrtho(0.0f, size.x, size.y, 0.0f, 0.0f, 1.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(position.x, position.y, 0);

	glClearColor(0.4f, 0.4f, 0.4f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void limon::Camera::End() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}
