//cabeceras de funciones para interfaz grafica
 



#ifdef __WIN32
#include "glut.h"  //PARA QUE FUNCIONE EN WINDOWS ES NECESARIO ESTE
#elif defined(__APPLE__)
#include "GLUT/glut.h"
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
 
