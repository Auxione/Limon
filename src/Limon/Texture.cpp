#include "Texture.h"
#include "GLFW/glfw3.h"

limon::Texture::Texture(const Image* img)
	:m_ImagePtr(img) {
	glGenTextures(1, &m_RendererID);
	glBindTexture(GL_TEXTURE_2D, m_RendererID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, (GLsizei) img->GetWidth(), (GLsizei) img->GetHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, img->GetPixels());
}

limon::Texture::~Texture() {
	glDeleteTextures(1, &m_RendererID);
}

void limon::Texture::Draw() {
	float width = (float) m_ImagePtr->GetWidth();
	float height = (float) m_ImagePtr->GetHeight();

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, m_RendererID);

	glBegin(GL_QUADS);

	glTexCoord2f(0.0, 0.0);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	//glColor4f((GLfloat) (color.red / 255), (GLfloat) (color.green / 255), (GLfloat) (color.blue / 255), (GLfloat) (color.alpha / 255));
	glVertex2f(-width / 2, -height / 2);

	glTexCoord2f(1.0, 0.0);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glVertex2f(+width / 2, -height / 2);

	glTexCoord2f(1.0, 1.0);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glVertex2f(+width / 2, +height / 2);

	glTexCoord2f(0.0, 1.0);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glVertex2f(-width / 2, +height / 2);

	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void limon::Texture::Send() {
	glBindTexture(GL_TEXTURE_2D, m_RendererID);
	glTexSubImage2D(GL_TEXTURE_2D,
					0,
					0,
					0,
					(GLsizei) m_ImagePtr->GetWidth(),
					(GLsizei) m_ImagePtr->GetHeight(),
					GL_RGBA,
					GL_UNSIGNED_BYTE,
					m_ImagePtr->GetPixels());
}
