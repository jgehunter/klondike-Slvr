#include "Posicion.h"

Posicion::Posicion() {}

void Posicion::setPosicionX( int x )
{
    posicionX = x;
}

void Posicion::setPosicionY( int y )
{
    posicionY = y;
}

int Posicion::getPosicionX( )
{
    return posicionX;
}

int Posicion::getPosicionY()
{
    return posicionY;
}

int Posicion::checkMovimiento( std::list<Tile> Lista)
{
    int mov = -1;

    for(std::list<Tile>::iterator it = Lista.begin(); it != Lista.end(); ++it)
    {
        if((it -> getPosicionX() == posicionX) && (it -> getPosicionY() == posicionY)) mov = it -> getMovimiento();
    }

    return mov;
}


