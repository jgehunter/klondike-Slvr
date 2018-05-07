//programa principal (contiene el bucle infinito que dibuja)


//#include "GLUT/glut.h"

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "GLstuff.h"
#include <utility>
#include <list>
#include <map>
#include <fstream>
#include <iostream>
#include "nodo.h"
#include "Figura.h"
#include "Personaje.h"




// PROTOTIPOS

//Callbacks de logica del programa
void myLogic();

//Callback de dibujo
void OnDibuja(void);	

//Callback de gestión del teclado
void OnKeyboardDown(unsigned char key, int x, int y);
void OnSpecKeyboardDown(int key, int x, int y);


// Variables globales

float xp=0;
float yp=0;
float zp=0;

float cam_pos[3]={0,-10,10};

Personaje pollito;


// Texture datas tructure
GLuint KLtexture;
GLuint Bgtexture;






//Main contiene las inicializaciones + bucle infinito
int main(int argc,char* argv[])
{

/**************************************************************/
    //INICILIZACION PROGRAMA HUNTER
    

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
/**************************************************************/
  // Inicializaciones OPEN GL

  // Inicialización GLUT
  glutInit(&argc, argv);

  // Inicializaciones openGL (ver GLstuff.c)
  init_GL_stuff();
  
  // Definición call backs de GLUT
  glutDisplayFunc(OnDibuja);
	
  glutIdleFunc(myLogic);

  glutKeyboardFunc(OnKeyboardDown);
  glutSpecialFunc(OnSpecKeyboardDown);
 
    
    // posicciona el punto de vista
  gluLookAt(cam_pos[0],cam_pos[1],cam_pos[2],       // posicion del  ojo
	    0.0, 0, 0.0,	// hacia que punto mira  
	    0.0, 1.0, 0.0);     // vector "UP"  (vertical positivo)

  // Carga la textura
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
 
   
   KLtexture= LoadTexture(900,1074,  "klondike.bmp");  //NO FUNIONA SI NO PONES el .bmp donde se crea el .exe
    
    
    
    glBindTexture (GL_TEXTURE_2D, KLtexture);
 
  /*Bgtexture=LoadTexture(900,1074, "klondike.bmp" );
  glBindTexture (GL_TEXTURE_2D, Bgtexture);*/
    
    
  // bucle del programa
  glutMainLoop();
  
  return 0;   
}
 






void myLogic()  // CONTIENE LAS ACTUALIZACIONES DEL PROGRAMA
{
/**************************************************************/
    
    
// PROGRAMA DE HUNTER QUE DA LAS Xp Yp Zp , Y LAS FUNCIONES QUE TRASLADAN EL MU„ECO (esto es un bucle ya de por si)
    
    
    
    
    
    
    
    //ejemplo trasladar mu–eco
  
    //xp=xp+0.01;      PRUEBA A USAR teclas         w
    // yp=yp+0.01;                                a s d

    
    //Ejemplos de acciones
    
    if(xp>5) xp = 0;
   // if(yp>5) yp = 0;
    
    if(yp>5) exit(1);
    
    
  
    
    
    
    
    
    
    
    
    
    
    
    
    
    
   
  
}

/**************************************************************/

void OnDibuja(void)
{
    //Borrado de la pantalla
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
/**************************************************************/
    
    // proyeccion de las figuras     DIBUJAR


    displaytext(KLtexture);
  //background(Bgtexture);
    pollito.mover(xp, yp, zp);
    pollito.draw();
    
  
    pollito.personaje_rot += 2.0;
    if(pollito.personaje_rot>360) pollito.personaje_rot = 0;
 
   
    
    
    glLoadIdentity();
/**************************************************************/
  // posicciona el punto de vista 
  gluLookAt(cam_pos[0],cam_pos[1],cam_pos[2],  // posicion del  ojo
	    0.0, 0, 0.0,		        // hacia que punto mira  
	    0.0, 1.0, 0.0);         // vector "UP"  (vertical positivo)

  //Al final, cambiar el buffer
  glutSwapBuffers();
  glutPostRedisplay();//se le indica que redibuje la pantalla
 
}


