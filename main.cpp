/**********************************************************************;
* Nombre del fichero        : main.cpp
*
* Autores                   : Jorge Hunter, Inaki Echevarria, Jose Miguel Hervas
*
* Finalidad                 : Programa principal que contiene las inicializaciones y la funcionalidad
*                             principal del programa
*
**********************************************************************/

#define _CRT_SECURE_NO_WARNINGS


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



// Definicion de prototipos de funciones

/*  Esta funcion suspende el subproceso que se está ejecutando durante al menos el tiempo introducido

    Input: tiempo en ms que debe bloquearse
*/

void mySleep(int sleepMs)
{
#ifdef __linux__
    usleep(sleepMs * 1000);
#endif
#ifdef __APPLE__
    usleep(sleepMs * 1000);
#endif // __APPLE__
#ifdef _WIN32
    Sleep(sleepMs);
#endif
}

// Definicion de variables globales

std::vector<Camino> coleccionFlechas; // Vector que almacena las flechas que muestran la solucion
std::map<std::pair<int,int>,int> tablero; // Mapa que contiene las posiciones del tablero y sus valores de movimiento
std::ifstream ficheroTablero; // Stream para leer el documento que contiene al tablero
std::list<Nodo*> OPEN; // Lista de punteros a nodos abiertos
std::list<Nodo> CLOSED; // Lista de nodos ya visitados
std::vector<Nodo> recorrido; // Vector que almacena los el recorrido de la solucion

void myLogic(); // Callback de logica del programa
void OnDibuja( void ); // Callback de dibujo
void OnKeyboardDown( unsigned char key, int x, int y ); // Callback de gestion de teclas
void OnSpecKeyboardDown( int key, int x, int y ); // Callback de gestion de teclas especiales

float xp = 0; // Posicion x del pollo
float yp = 0; // Posicion y del pollo
float zp = 0; // Posicion z del pollo
float cam_pos[3] = {0,-10,10}; // Posicion desde la que miramos

int posX = 0; // Variable usada para leer el documento con el tablero
int posY = 0; // Variable usada para leer el documento con el tablero
int mov; // Variable usada para leer el documento con el tablero
int flagExit; // Flag que marca si hemos encontrado la solucion
int flagPath; // Flag que marca si hemos terminado de encontrar el camino que lleva a la solucion
int flagEnded; // Flag que marca si hemos terminado de crear las flechas de la solucion

Personaje pollito; // Pollo que vamos a dibujar

Camino camino; // Flecha entre dos casillas

Nodo* nodoActual; // Puntero al nodo con el que estamos operando
Nodo* nodoPlaceholder; // Puntero a un nodo que utilizamos para operaciones intermedias

GLuint KLtexture; // Datos de la imagen del tablero de klondike
GLuint Bgtexture; // Datos de la imagen del background del tablero

int main( int argc, char* argv[] )
{
    /*  A continuación realizamos las operaciones para leer y almacenar el mapa de coordenadas del tablero y el valor
        del movimiento para cada posicion
    */

    ficheroTablero.open( "Tablero.txt" );
    while(ficheroTablero >> posX >> posY >> mov)
    {
        tablero[std::make_pair( posX, posY )] = mov;
    }

    /* Inicializamos las flags a 0
    */

    flagPath = 0;
    flagExit = 0;
    flagEnded = 0;


    /* Creamos el nodo inicial en el (0,0) y lo introducimos en la lista de nodos abiertos
    */

    nodoActual = new Nodo;
    nodoPlaceholder = new Nodo;

    nodoActual->Setcoordenadas( std::make_pair(0,0) );
    nodoActual->Setparent( nodoPlaceholder );
    nodoPlaceholder->Setparent( nullptr );

    OPEN.push_back( nodoActual );

    /* Establecemos las inicializaciones de OPEN GL
    */

    glutInit(&argc, argv);

    init_GL_stuff();

    glutDisplayFunc(OnDibuja);
    glutIdleFunc(myLogic);
    glutKeyboardFunc(OnKeyboardDown);
    glutSpecialFunc(OnSpecKeyboardDown);


    /* Posicionamos el punto de vista
    */

    gluLookAt(cam_pos[0],cam_pos[1],cam_pos[2],
              0.0, 0, 0.0,
              0.0, 1.0, 0.0);

    /* Cargamos las texturas
    */

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    KLtexture= LoadTexture(900,1074,  "klondike.bmp");  //NO FUNIONA SI NO PONES el .bmp donde se crea el .exe
    glBindTexture (GL_TEXTURE_2D, KLtexture);

    Bgtexture=LoadTexture(800,500, "montana.bmp" );
    glBindTexture (GL_TEXTURE_2D, Bgtexture);

    /* Entramos en el bucle principal de glut
    */

    glutMainLoop();

    return 0;
}

void myLogic()
{

    /* Ralentizamos el ritmo del programa
    */

    mySleep(50);

    /* Establecemos unos limites para el movimiento de la camara
    */

    if (cam_pos[0]>4) cam_pos[0]=4;
    if (cam_pos[1]>0) cam_pos[1]=0;
    if (cam_pos[2]>15) cam_pos[2]=15;

    if (cam_pos[0]<-4) cam_pos[0]=-4;
    if (cam_pos[1]<-10) cam_pos[1]=-10;
    if (cam_pos[2]<2) cam_pos[2]=2;

    /*  Vamos haciendo la busqueda de nodos en amplitud hasta que llegamos a la solucion,
        una vez encontrada la solucion guardamos el recorrido de como hemos legado hasta ella
        y por ultimo creamos y guardamos las flechas para representar ese recorrido
    */

    if( !flagExit ){
        nodoActual = OPEN.front();
        OPEN.pop_front();
        nodoActual->Crearhijos( CLOSED, OPEN, nodoActual, tablero );

        for( auto iter : nodoActual->Gethijos() ){
            OPEN.push_back( iter );
            CLOSED.push_back( *iter );
        }

        if( OPEN.empty() || nodoActual->Comprobarmovimiento( tablero ) == 0 ) flagExit = 1;

        xp = 0.42*nodoActual->Getcoordenadas().first;
        yp = -0.15+0.35*nodoActual->Getcoordenadas().second;

    } else {
        if( !flagPath ){
            while( nodoActual->Getparent() != nullptr ) {
                recorrido.push_back( *nodoActual );
                nodoActual = nodoActual->Getparent();
            }
            flagPath = 1;
        }
        else {
            if( !flagEnded ){
                std::vector<Nodo>::reverse_iterator rit = recorrido.rbegin();
                do {
                    camino.siguientes( rit->Getcoordenadas().first, rit->Getcoordenadas().second );
                    camino.elegirColor();
                    coleccionFlechas.push_back( camino );
                    rit++;
                } while( rit != recorrido.rend() );
            camino.siguientes(0,0);
            flagEnded = 1;
            }
        }
    }

}

void OnDibuja(void)
{
    /* Borramos el display
    */

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /* Dibujamos las texturas
    */

    displaytext(KLtexture);
    background(Bgtexture);

    /* Movemos la posicion del pollo y lo dibujamos, asi como las flechas si ya estan dibujadas
    */

    pollito.mover(xp, yp, zp);
    pollito.personaje_rot += 2.0;
    if(pollito.personaje_rot>360) pollito.personaje_rot = 0;

    pollito.draw();

    for(auto iter : coleccionFlechas){
        iter.draw();
    }

    /*  Posicionamos la camara y intercambiamos el buffer sobre el que estamos dibujando y el que
        esta siendo representado
    */

    glLoadIdentity();

    gluLookAt(cam_pos[0],cam_pos[1],cam_pos[2],
              0.0, 0, 0.0,
              0.0, 1.0, 0.0);

    glutSwapBuffers();
    glutPostRedisplay();

}


