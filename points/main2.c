// Points.c
// OpenGL SuperBible
// Demonstrates OpenGL Primative GL_POINTS
// Program by Richard S. Wright Jr.

#include <GL/glut.h>    // Header File For The GLUT Library 
#include <GL/gl.h>	// Header File For The OpenGL32 Library
#include <GL/glu.h>	// Header File For The GLu32 Library
#include <unistd.h>     // Header file for sleeping.
#include <stdio.h>      // Header file for standard file i/o.
#include <stdlib.h>     // Header file for malloc/free.
#include <string.h>
#include <math.h>


// Define a constant for the value of PI
#define GL_PI 3.1415f

// Rotation amounts
static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;


// Called to draw scene
void RenderScene(void)
{
    GLfloat x,y,z,angle; // Storeage for coordinates and angles

    // Clear the window with current clearing color
    glClear(GL_COLOR_BUFFER_BIT);

    // Save matrix state and do the rotation
    glPushMatrix();
    glRotatef(xRot, 1.0f, 0.0f, 0.0f);
    glRotatef(yRot, 0.0f, 1.0f, 0.0f);

    // Call only once for all remaining points
    glBegin(GL_POINTS);

    z = -50.0f;
    for(angle = 0.0f; angle <= (2.0f*GL_PI)*3.0f; angle += 0.1f)
    {
	x = 50.0f*sin(angle);
	y = 50.0f*cos(angle);
	
	// Specify the point and move the Z value up a little	
	glVertex3f(x, y, z);
	z += 0.5f;
    }

    // Done drawing points
    glEnd();

    // Restore transformations
    glPopMatrix();

    // Flush drawing commands
    glutSwapBuffers();
}

// This function does any needed initialization on the rendering
// context. 
void SetupRC()
{
    // Black background
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f );

    // Set drawing color to green
    glColor3f(0.0f, 1.0f, 0.0f);
}

void SpecialKeys(int key, int x, int y)
{
    printf("key=%d, x=%d, y=%d\n", key, x, y);
    fflush(stdout);

    if(key == GLUT_KEY_UP)
	xRot-= 5.0f;

    if(key == GLUT_KEY_DOWN)
	xRot += 5.0f;

    if(key == GLUT_KEY_LEFT)
	yRot -= 5.0f;

    if(key == GLUT_KEY_RIGHT)
	yRot += 5.0f;

    if(key > 356.0f)
	xRot = 0.0f;

    if(key < -1.0f)
	xRot = 355.0f;

    if(key > 356.0f)
	yRot = 0.0f;

    if(key < -1.0f)
	yRot = 355.0f;

    // Refresh the Window
    glutPostRedisplay();
}


void ChangeSize(int w, int h)
{
    GLfloat nRange = 100.0f;

    // Prevent a divide by zero
    if(h == 0)
	h = 1;

    // Set Viewport to window dimensions
    glViewport(0, 0, w, h);

    // Reset projection matrix stack
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Establish clipping volume (left, right, bottom, top, near, far)
    if (w <= h) 
	glOrtho (-nRange, nRange, -nRange*h/w, nRange*h/w, -nRange, nRange*10);
    else 
	glOrtho (-nRange*w/h, nRange*w/h, -nRange, nRange, -nRange, nRange*10);

    // Reset Model view matrix stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    /*
     * GLUT_DOUBLE: 指定双缓存窗口
     * GLUT_RGB:    指定RGB颜色窗口
     * GLUT_DEPTH:  指定适用深度缓存
     */
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutCreateWindow("Points Example");

    //Reshape: 窗口形状改变时调用的call back。
    glutReshapeFunc(ChangeSize);

    //指定当前窗口键盘事件回调。
    /* The key callback parameter is a GLUT_KEY_* constant for 
     * the special key pressed. 
     * The x and y callback parameters indicate the mouse in 
     * window relative coordinates when the key was pressed. 
    */
    glutSpecialFunc(SpecialKeys);

    //相当于paintEvent的回调。
    glutDisplayFunc(RenderScene);

    SetupRC();
    glutMainLoop();

    return 0;
}
