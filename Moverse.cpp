#include <iostream>
#include "Moverse.h"
#include "Posicion.h"
#include "sig.h"
#include "Tile.h"

Moverse::Moverse() {}

void Moverse::setMovimientoX(int x)
{
    movimientoX = x;
}

void Moverse::setMovimientoY(int y)
{
    movimientoY = y;
}

void Moverse::setMovimiento(int mov)
{
    movimiento = mov;
}

void Moverse::mover(int inicialX, int inicialY, std::list<Tile> Tablero, Posicion* nuevaPosicion)
{
    int currentX = inicialX;
    int currentY = inicialY;
    int outFlag = 0;
    Posicion* tmpNuevaPos = 0;

    for(int i=0; i < movimiento; i++)
    {
        currentX += movimientoX;
        currentY += movimientoY;

        Posicion posicionTransitoria;
        posicionTransitoria.setPosicionX(currentX);
        posicionTransitoria.setPosicionY(currentY);

        if((i != (movimiento - 1)) && ( posicionTransitoria.checkMovimiento(Tablero) == 0 || posicionTransitoria.checkMovimiento(Tablero) == -1)) outFlag = 1;
        if((i == movimiento - 1) && outFlag == 0){
            nuevaPosicion->setPosicionX(posicionTransitoria.getPosicionX());
            nuevaPosicion->setPosicionY(posicionTransitoria.getPosicionY());
        }   else if(i == movimiento - 1)
                    {
                        *&nuevaPosicion = tmpNuevaPos;
                    }
    }
}
