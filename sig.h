#ifndef SIG_H_INCLUDED
#define SIG_H_INCLUDED

#include <list>
#include "Posicion.h"
#include "Tile.h"


void sig(Posicion posicionActual, std::list<Posicion>& OPEN, std::list<Posicion>& CLOSED, std::list<Tile> Tablero);


#endif // SIG_H_INCLUDED
