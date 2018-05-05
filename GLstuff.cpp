//Contiene los parametros de la interfaz grafica

#include <iostream>
#include <stdio.h>
#include <errno.h>
#include "GLstuff.h"

extern float xp;
extern float yp;
extern float cam_pos[];



void OnKeyboardDown(unsigned char key, int x, int y)
{
  switch(key)
    {
    case 'q':
    case ESC:     exit(1);  
    
   
            
    case 'w': yp=yp+0.4;
            break;
    case 's': yp=yp-0.4;
            break;
    case 'd': xp=xp+0.4;
            break;
    case 'a': xp=xp-0.4;
            break;
    
        
    }		
}


    
void OnSpecKeyboardDown(int key, int x, int y)
{
    switch(key)
    {
            
        case GLUT_KEY_DOWN: cam_pos[2]+=1;
            break;
        case GLUT_KEY_UP: cam_pos[2]-=1;
            break;
        case GLUT_KEY_LEFT: cam_pos[1]+=1;
            break;
        case GLUT_KEY_RIGHT: cam_pos[1]-=1;
            break;
        case GLUT_KEY_PAGE_DOWN: cam_pos[0]+=1;
            break;
        case GLUT_KEY_PAGE_UP: cam_pos[0]-=1;
            break;

            
            
    }

}



void init_GL_stuff()
{


  //Creacion y definicion de la ventana
    
  glutInitWindowSize(ANCHO,ALTO);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutCreateWindow("Klondike");

  //Habilitar las luces, la renderizacion y el color de los materiales
  glEnable(GL_LIGHT0);
  glEnable(GL_LIGHTING);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_COLOR_MATERIAL);
	
  //definir la proyeccion
  glMatrixMode(GL_PROJECTION);
  gluPerspective( 40.0, ANCHO/ALTO, 0.1, 50);

  
  // color del fondo
  glClearColor(0/255.0, 153/255.0, 0/255.0, 0.5f); // RGB

	
  // Define el punto de vista
  glMatrixMode(GL_MODELVIEW);	
  
 
}


GLuint LoadTexture( int width, int height, const char * filename )
{

  GLuint texture;

 
  unsigned char * data;

  FILE * file; /* como debemos trabajar, con los ficheros en modo C o en modo C++? en C++ seria con lo de fstream y tal */
    
 file = fopen( filename, "rb" );

 if (file == NULL) {
        perror("klondike.bmp");
        printf("Error %d \n", errno);
        return 0;}
   
    
    if ( file == NULL ) return 0;
   
    data = (unsigned char *)malloc( width * height * 3 );
  //int size = fseek(file,);
  fread( data, width * height * 3, 1, file );
  fclose( file );

  for(int i = 0; i < width * height ; ++i)
    {
      int index = i*3;
      unsigned char B,R;
      B = data[index];
      R = data[index+2];
      
      data[index] = R;
      data[index+2] = B;
      
    }
  
  
  glGenTextures( 1, &texture );
  glBindTexture( GL_TEXTURE_2D, texture );
  glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE );
  
  glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST );
  glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );
  
    
  glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT );
  glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT );
  
    

 gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height,GL_RGB, GL_UNSIGNED_BYTE, data );
  free( data );
  
  return texture;
}


void displaytext(GLuint Thetexture)
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glEnable(GL_TEXTURE_2D);
   glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
   
    
glBindTexture(GL_TEXTURE_2D, Thetexture);
   glBegin(GL_QUADS);
   glTexCoord2f(0.0, 0.0); glVertex3f(-5.0, -5.0, 0.0);
   glTexCoord2f(0.0, 1.0); glVertex3f(-5.0, 5.0, 0.0);
   glTexCoord2f(1.0, 1.0); glVertex3f(5.0, 5.0, 0.0);
   glTexCoord2f(1.0, 0.0); glVertex3f(5.0, -5.0, 0.0);

   glEnd();
   glFlush();
   glDisable(GL_TEXTURE_2D);
}


 //INTENTO DE PONER IMAGEN DE FONDO

/*void background (GLuint texture) {
    
   glBindTexture( GL_TEXTURE_2D, texture );
    
    
   glBegin(GL_QUADS);
      glTexCoord2f(0.0, 0.0); glVertex3f(-70.0, -5.0, 0.0);
     glTexCoord2f(0.0, 1.0); glVertex3f(-5.0, 5.0, 0.0);
     glTexCoord2f(1.0, 1.0); glVertex3f(5.0, 5.0, 0.0);
   glTexCoord2f(1.0, 0.0); glVertex3f(5.0, -5.0, 0.0);
        
   glEnd();
    glFlush();
    glDisable(GL_TEXTURE_2D);
} */

 

 
