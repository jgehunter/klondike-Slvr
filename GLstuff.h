//cabeceras de funciones para interfaz grafica
 


#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#ifdef _WIN32
#include <windows.h>
#endif
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
//void background (GLuint texture);

void init_GL_stuff();
 
