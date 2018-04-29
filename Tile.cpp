#include "Tile.h"

Tile::Tile()
{
  posicionX = -1;
  posicionY = -1;
  movimiento = -1;
}

int Tile::getPosicionX()
{
    return posicionX;
}

int Tile::getPosicionY()
{
    return posicionY;
}

int Tile::getMovimiento()
{
    return movimiento;
}

void Tile::setPosicionX( int x )
{
    posicionX = x;
}

void Tile::setPosicionY( int y )
{
    posicionY = y;
}

void Tile::setMovimiento( int m )
{
    movimiento = m;
}
