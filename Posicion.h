#ifndef POSICION_H_INCLUDED
#define POSICION_H_INCLUDED

#include <list>
#include "Tile.h"

class Posicion
{
    private:
        int posicionX;
        int posicionY;

    public:
        Posicion();
        void setPosicionX(int x);
        void setPosicionY(int y);
        int getPosicionX();
        int getPosicionY();
        int checkMovimiento(std::list<Tile> Lista);

};


#endif // POSICION_H_INCLUDED
