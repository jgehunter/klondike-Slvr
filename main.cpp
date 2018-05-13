//programa principal (contiene el bucle infinito que dibuja)
#define _CRT_SECURE_NO_WARNINGS

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
#include "Camino.h"

#ifdef __linux__
#include <unistd.h>
#endif
#ifdef __APPLE__
#include <unistd.h>
#endif

#ifdef _WIN32
#include <windows.h>
#endif



// PROTOTIPOS

// Función para ralentizar el programa
void mySleep(int sleepMs)
{
#ifdef __linux__
    usleep(sleepMs * 1000);   // usleep takes sleep time in us (1 millionth of a second)
#endif
#ifdef __APPLE__
    usleep(sleepMs * 1000);   // usleep takes sleep time in us (1 millionth of a second)
#endif // __APPLE__
#ifdef _WIN32
    Sleep(sleepMs);
#endif
}

//Callbacks de logica del programa
void myLogic();

//Callback de dibujo
void OnDibuja(void);

//Callback de gesti—n del teclado
void OnKeyboardDown(unsigned char key, int x, int y);
void OnSpecKeyboardDown(int key, int x, int y);




// Variables globales

float xp=0;
float yp=0;
float zp=0;

float cam_pos[3]={0,-10,10};

Personaje pollito;
Camino camino;

//INICILIZACION PROGRAMA HUNTER
/**************************************************************/



std::map<std::pair<int,int>,int> tablero;
std::ifstream ficheroTablero;

int posX=0;
int posY=0;
int mov;

Nodo* nodoActual;
Nodo* nodoPlaceholder;
Nodo* nodoInicio;


std::list<Nodo*> OPEN;
std::list<Nodo> CLOSED;

int contador;
int flagExit;
int flagPath;
int flagClear;
int flagEnd;

Nodo *nodoVisitado1;

std::vector<Nodo> recorrido;







/**************************************************************/


// Texture datas tructure
GLuint KLtexture;
GLuint Bgtexture;



//Main contiene las inicializaciones + bucle infinito
int main(int argc,char* argv[])
{

    // Inicializaciones programa logica

    ficheroTablero.open("Tablero.txt");

    while(ficheroTablero >> posX >> posY >> mov){
        tablero[std::make_pair(posX,posY)] = mov;
    }

    nodoActual = new Nodo;
    nodoPlaceholder = new Nodo;
    nodoInicio = new Nodo;

    nodoActual->Setcoordenadas(std::make_pair(0,0));
    nodoActual->Setparent(nodoPlaceholder);
    nodoPlaceholder->Setparent(nullptr);
    nodoInicio = nodoActual;

    OPEN.push_back(nodoActual);

    contador = 0;

    flagPath = 0;
    flagExit = 0;
    flagEnd = 0;


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
              0.0, 0, 0.0,    // hacia que punto mira
              0.0, 1.0, 0.0);     // vector "UP"  (vertical positivo)

    // Carga la textura
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);


    KLtexture= LoadTexture(900,1074,  "klondike.bmp");  //NO FUNIONA SI NO PONES el .bmp donde se crea el .exe
    glBindTexture (GL_TEXTURE_2D, KLtexture);


    Bgtexture=LoadTexture(800,500, "montana.bmp" );


    glBindTexture (GL_TEXTURE_2D, Bgtexture);


    // bucle del programa
    glutMainLoop();

    return 0;
}







void myLogic()  // CONTIENE LAS ACTUALIZACIONES DEL PROGRAMA
{
    /**************************************************************/

    //mySleep(50);

    // PROGRAMA DE HUNTER QUE DA LAS Xp Yp Zp , Y LAS FUNCIONES QUE TRASLADAN EL MU„ECO (esto es un bucle ya de por si)

    if(!flagExit){
        nodoActual = OPEN.front();
        OPEN.pop_front();
        nodoActual->Crearhijos( CLOSED, OPEN, nodoActual, tablero );

        for( auto iter : nodoActual->Gethijos()){
            OPEN.push_back(iter);
            contador++;
            CLOSED.push_back(*iter);
        }

        if( OPEN.empty() || nodoActual->Comprobarmovimiento( tablero ) == 0 ) flagExit = 1;

        std::cout << "x y actuales: " << nodoActual->Getcoordenadas().first << " " << nodoActual->Getcoordenadas().second << std::endl;

        xp=0.42*nodoActual->Getcoordenadas().first;
        yp=-0.15+0.35*nodoActual->Getcoordenadas().second;

    } else {
        if(!flagPath){
            while(nodoActual->Getparent() != nullptr) {
                recorrido.push_back(*nodoActual);
                nodoActual = nodoActual->Getparent();
            }
            flagPath = 1;
        }
    }

    if(flagExit && flagPath && !flagEnd){
        int paso;
        paso = 0;
        for(auto iter: recorrido){
            std::cout << "El paso " << paso << " es " << iter.Getcoordenadas().first << " " << iter.Getcoordenadas().second << std::endl;
            paso++;
        }
        flagEnd = 1;
    }

    /**************************************************************/


}

/**************************************************************/

void OnDibuja(void)
{
    //Borrado de la pantalla
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    /**************************************************************/

    // proyeccion de las figuras     DIBUJAR

    displaytext(KLtexture);
    background(Bgtexture);


    pollito.mover(xp, yp, zp);
    pollito.draw();

   camino.draw();




     if(flagEnd){
        std::vector<Nodo>::reverse_iterator rit = recorrido.rbegin();
        int BORRAR = 0;
        do{
            std::cout << "DATO "  << BORRAR << std::endl;
            std::cout << "x e y: " << rit->Getcoordenadas().first << " " << rit->Getcoordenadas().second << std::endl;
            camino.siguientes(rit->Getcoordenadas().first, rit->Getcoordenadas().second);
            camino.draw();
            BORRAR++;
            rit++;
        } while(rit != recorrido.rend());
        }





    pollito.personaje_rot += 2.0;
    if(pollito.personaje_rot>360) pollito.personaje_rot = 0;




    glLoadIdentity();
    /**************************************************************/
    // posicciona el punto de vista
    gluLookAt(cam_pos[0],cam_pos[1],cam_pos[2],  // posicion del  ojo
              0.0, 0, 0.0,                // hacia que punto mira
              0.0, 1.0, 0.0);         // vector "UP"  (vertical positivo)

    //Al final, cambiar el buffer
    glutSwapBuffers();
    glutPostRedisplay();//se le indica que redibuje la pantalla

}


