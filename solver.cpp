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
}

