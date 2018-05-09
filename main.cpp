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


//INICILIZACION PROGRAMA HUNTER
/**************************************************************/



std::map<std::pair<int,int>,int> tablero;
std::ifstream ficheroTablero;

int posX;
int posY;
int mov;
















/**************************************************************/


// Texture datas tructure
GLuint KLtexture;
GLuint Bgtexture;



//Main contiene las inicializaciones + bucle infinito
int main(int argc,char* argv[])
{


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
    
    
   ficheroTablero.open("Tablero.txt");
     
     while(ficheroTablero >> posX >> posY >> mov){
     tablero[std::make_pair(posX,posY)] = mov;
     }
     
     Nodo* nodoActual;
     Nodo* nodoPlaceholder;
     Nodo* nodoInicio;
     nodoActual = new Nodo;
     nodoPlaceholder = new Nodo;
     nodoInicio = new Nodo;
     
     nodoActual->Setcoordenadas(std::make_pair(0,0));
     nodoActual->Setparent(nodoPlaceholder);
     nodoPlaceholder->Setparent(nullptr);
     nodoInicio = nodoActual;
     
     std::list<Nodo*> OPEN;
     std::list<Nodo> CLOSED;
     
     OPEN.push_back(nodoActual);
     CLOSED.push_back(*nodoActual);
     
    
    
    
    int contador = 0;
    for(;;){
     nodoActual = OPEN.front();
     OPEN.pop_front();
     nodoActual->Crearhijos( CLOSED, OPEN, nodoActual, tablero );
     for( auto iter : nodoActual->Gethijos()){
     OPEN.push_back(iter);
     contador++;
     CLOSED.push_back(*iter);
     }
        if( OPEN.empty() || nodoActual->Comprobarmovimiento( tablero ) == 0 ) break;
     
        std::cout << "x y actuales: " << nodoActual->Getcoordenadas().first << " " << nodoActual->Getcoordenadas().second << std::endl;
     
         xp=nodoActual->Getcoordenadas().first;
         yp=nodoActual->Getcoordenadas().second;
         
     }
     
    
    
    std::cout << "La posicion final es: " << nodoActual->Getcoordenadas().first << " " << nodoActual->Getcoordenadas().second << std::endl;
    
    
    
    
    
    
    
    
    
    
     Nodo *nodoVisitado1 = nodoActual;
     std::vector<Nodo> recorrido;
     
     while(nodoVisitado1->Getparent() != nullptr) {
     recorrido.push_back(*nodoVisitado1);
     nodoVisitado1 = nodoVisitado1->Getparent();
     }
     
     int flagLeaf = 0;
     do {
     if(nodoInicio->Gethijos().size() == 0) flagLeaf = 1;
     if(!flagLeaf) nodoInicio = nodoInicio->Gethijos().back();
     if(flagLeaf){
     Nodo* nodoTemp;
     nodoTemp = nodoInicio->Getparent();
     delete nodoInicio;
     nodoInicio = nodoTemp;
     nodoInicio->Gethijos().pop_back();
     if(nodoInicio->Getparent() == nullptr) break;
     }
     flagLeaf = 0;
     } while(1) ;
     delete nodoInicio;
     
     
     
     
     
     
     
    
    
    
    
    
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


