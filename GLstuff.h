//cabeceras de funciones para interfaz grafica


/*
 como instalar libreria OpenGL en cada SO
 http://web.eecs.umich.edu/~sugih/courses/eecs487/glut-howto/
 */

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#endif

#ifdef _WIN32
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "glut.h"
#endif

#ifdef __linux__
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif


#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define  ANCHO 800
#define ALTO 800

#define ESC 27

// Prototipos de funciones
GLuint LoadTexture(int, int, const char * filename );

void displaytext(GLuint Thetexture);

void background (GLuint texture);

void init_GL_stuff();

