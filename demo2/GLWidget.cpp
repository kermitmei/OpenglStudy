#include "GLWidget.h"
//#include "qtglut.h"

extern "C" {
#include <GL/gl.h>
#include <GL/glx.h>
#include <GL/glu.h>
#include <GL/glut.h>
}


GLWidget::GLWidget(QWidget *parent)
    : QGLWidget(parent)
{ /* Do Nothing Here! */ }

GLWidget::~GLWidget()
{ /* Do Nothing Here! */ }

void GLWidget::initializeGL()
{
    //InitializeAWindowPlease();

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    //    glutDisplayFunc(GLWidget::display);
    //    glutReshapeFunc(GLWidget::reshape);
}


void GLWidget::paintGL()
{
    display();
}

void GLWidget::display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glLoadIdentity();   //Clear the matrix
    
    /* Viewing transformation */
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glScalef(1.0, 2.0, 1.0); /* modeling transformation */
    //    glutWireCube(1.0);
    glFlush();
}

void GLWidget::reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
    glMatrixMode(GL_MODELVIEW);
}
