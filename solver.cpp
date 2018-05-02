#include <utility>
#include <list>
#include <map>
#include <fstream>
#include <iostream>
#include "nodo.h"

int main()
{
    std::map<std::pair<int,int>,int> tablero;
    std::ifstream ficheroTablero;
    ficheroTablero.open("Tablero.txt");
    int posX;
    int posY;
    int mov;
    while(ficheroTablero >> posX >> posY >> mov){
        tablero[std::make_pair(posX,posY)] = mov;
    }

    Nodo* nodoActual;
    nodoActual = new Nodo;

    nodoActual->Setcoordenadas(std::make_pair(0,0));
    nodoActual->Setparent(nullptr);

    std::list<Nodo*> OPEN;
    std::list<Nodo> CLOSED;

    OPEN.push_back(nodoActual);
    CLOSED.push_back(*nodoActual);

    for(;;){
        nodoActual = OPEN.front();
        OPEN.pop_front();
        nodoActual->Crearhijos( CLOSED, OPEN, nodoActual, tablero );
        for( auto iter : nodoActual->Gethijos()){
            OPEN.push_front(iter);
            CLOSED.push_back(*iter);
        }
        if( OPEN.empty() || (nodoActual->Comprobarmovimiento( tablero ) == 0)) break;
        /*std::cout << "xy antes de quitar: " << OPEN.front()->Getcoordenadas().first << " " << OPEN.front()->Getcoordenadas().second << std::endl;
        std::cout << "xy despues de quitar: " << OPEN.front()->Getcoordenadas().first << " " << OPEN.front()->Getcoordenadas().second << std::endl;*/
        std::cout << "x y actuales: " << nodoActual->Getcoordenadas().first << " " << nodoActual->Getcoordenadas().second << std::endl;
}

    std::cout << "La posicion final es: " << nodoActual->Getcoordenadas().first << " " << nodoActual->Getcoordenadas().second << std::endl;
    

    // AQUI FALTA POR IR ITERANDO Y BORRANDO TODOS LOS NODOS CREADOS, A LA VEZ PODEMOS IR GUARDANDO EL CAMINO EN UN VECTOR O ALGO ASI PARA TENER GUARDADO EL CAMINO A LA SOLUCION//
}
