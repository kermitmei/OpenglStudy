//
// This code was created by Jeff Molofee '99 (ported to Linux/GLUT by Richard Campbell '99)
//
// If you've found this code useful, please let me know.
//
// Visit me at www.demonews.com/hosted/nehe 
// (email Richard Campbell at ulmont@bellsouth.net)
//
#include <GL/glut.h>    // Header File For The GLUT Library 
#include <GL/gl.h>	// Header File For The OpenGL32 Library
#include <GL/glu.h>	// Header File For The GLu32 Library
#include <unistd.h>     // Header file for sleeping.
#include <stdio.h>      // Header file for standard file i/o.
#include <stdlib.h>     // Header file for malloc/free.
#include <string.h>
#include <math.h>

/* ascii codes for various special keys */
#define ESCAPE 27
#define PAGE_UP 73
#define PAGE_DOWN 81
#define UP_ARROW 72
#define DOWN_ARROW 80
#define LEFT_ARROW 75
#define RIGHT_ARROW 77

/* The number of our GLUT window */
int window; 

/* lighting on/off (1 = on, 0 = off) */
int light;

/* L pressed (1 = yes, 0 = no) */
int lp;

/* F pressed (1 = yes, 0 = no) */
int fp;


GLfloat xrot;   // x rotation 
GLfloat yrot;   // y rotation 
GLfloat xspeed; // x rotation speed
GLfloat yspeed; // y rotation speed

GLfloat z=-5.0f; // depth into the screen.

/* white ambient light at half intensity (rgba) */
GLfloat LightAmbient[] = { 0.5f, 0.5f, 0.5f, 1.0f };

/* super bright, full intensity diffuse light. */
GLfloat LightDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };

/* position of light (x, y, z, (position of light)) */
GLfloat LightPosition[] = { 0.0f, 0.0f, 2.0f, 1.0f };

GLuint	filter;			/* Which Filter To Use (nearest/linear/mipmapped) */
GLuint	texture[3];		/* Storage for 3 textures. */

#define GL_PI 3.1416f

void setupRC(void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
}

void RenderScene(void)
{
    GLfloat x,y,z,angle;
    GLfloat sizes[2];
    GLfloat step;
    GLfloat curSize;

    glGetFloatv(GL_POINT_SIZE_RANGE, sizes);
    glGetFloatv(GL_POINT_SIZE_GRANULARITY, &step);

    curSize = sizes[0];

    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);

    glBegin(GL_POINTS);

    z = -50.f;
    for(angle = 0.0f; angle <= (2.0f*GL_PI)*3.0f; angle += 0.1) {
	x = 50.0f * sin(angle);
	y = 50.0f * cos(angle);

	glVertex3f(x, y, z);
	z += 0.5f;
	curSize += step;
	printf("(%f,%f,%f), ", x,y,z);
    }
    fflush(stdout);    
    glEnd();

    //恢复变换
    glPopMatrix();

    //刷新绘图命令
    glutSwapBuffers();
}

void reshape(int w, int h)                                                      
{                                                                               
    glViewport(0,0,(GLsizei) w, (GLsizei) h);                                   
    glMatrixMode(GL_PROJECTION);                                                
    glLoadIdentity();                                                           
    //glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);                               
    gluPerspective(60.0, 1.0, 1.5, 20.0);                                       
    glMatrixMode(GL_MODELVIEW);                                                 
}   

/* The function called whenever a normal key is pressed. */
void keyPressed(unsigned char key, int x, int y) 
{
    /* avoid thrashing this procedure */
    usleep(100);

    switch (key) {
    case ESCAPE: // kill everything.
	/* shut down our window */
	glutDestroyWindow(window); 
	
	/* exit the program...normal termination. */
	exit(1);                   	
	break; // redundant.

    case 76: 
    case 108: // switch the lighting.
	printf("L/l pressed; light is: %d\n", light);
	light = light ? 0 : 1;              // switch the current value of light, between 0 and 1.
	printf("Light is now: %d\n", light);
	if (!light) {
	    glDisable(GL_LIGHTING);
	} else {
	    glEnable(GL_LIGHTING);
	}
	break;

    case 70:
    case 102: // switch the filter.
	printf("F/f pressed; filter is: %d\n", filter);
	filter+=1;
	if (filter>2) {
	    filter=0;	
	}	
	printf("Filter is now: %d\n", filter);
	break;

    default:
	break;
    }	
}

/* The function called whenever a normal key is pressed. */
void specialKeyPressed(int key, int x, int y) 
{
    /* avoid thrashing this procedure */
    usleep(100);

    switch (key) {    
    case GLUT_KEY_PAGE_UP: // move the cube into the distance.
	z-=0.02f;
	break;
    
    case GLUT_KEY_PAGE_DOWN: // move the cube closer.
	z+=0.02f;
	break;

    case GLUT_KEY_UP: // decrease x rotation speed;
	xspeed-=0.01f;
	break;

    case GLUT_KEY_DOWN: // increase x rotation speed;
	xspeed+=0.01f;
	break;

    case GLUT_KEY_LEFT: // decrease y rotation speed;
	yspeed-=0.01f;
	break;
    
    case GLUT_KEY_RIGHT: // increase y rotation speed;
	yspeed+=0.01f;
	break;

    default:
	break;
    }	
}

int main(int argc, char **argv) 
{  
    glutInit(&argc, argv);  
    setupRC();
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);  
    glutInitWindowSize(640, 480);  
    glutInitWindowPosition(0, 0);  

    /* Open a window */  
    window = glutCreateWindow("Points roll window");  
    
    /* Go fullscreen.  This is as soon as possible. */
    //glutFullScreen();

    /* Even if there are no events, redraw our gl scene. */

    //glutIdleFunc(&RenderScene);

    /* Register the function called when our window is resized. */

    glutDisplayFunc(&RenderScene);
    glutReshapeFunc(&reshape);

    /* Register the function called when the keyboard is pressed. */
    glutKeyboardFunc(&keyPressed);

    glutSpecialFunc(&specialKeyPressed);

    /* Initialize our window. */
    //InitGL(640, 480);
  
    /* Start Event Processing Engine */  
    glutMainLoop();  

    return 1;
}

