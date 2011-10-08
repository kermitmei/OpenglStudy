#include "GLWidget.h"

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

GLWidget::GLWidget(QWidget *parent)
    : QGLWidget(parent)
{ /* Do Nothing Here! */ }

GLWidget::~GLWidget()
{ /* Do Nothing Here! */ }

void GLWidget::initializeGL()
{
    //InitializeAWindowPlease();
    qDebug("void GLWidget::initializeGL()");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

    glBegin(GL_POLYGON);
    glVertex3f(0.25, 0.25, 0.0);
    glVertex3f(0.75, 0.25, 0.0);
    glVertex3f(0.75, 0.75, 0.0);
    glVertex3f(0.25, 0.75, 0.0);
    glEnd();
    glFlush();

}


void GLWidget::paintGL()
{
    qDebug("void GLWidget::paintGL()");
}
