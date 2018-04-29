#include <list>
#include <iostream>
#include <iterator>
#include "sig.h"
#include "Posicion.h"
#include "Moverse.h"

void sig(Posicion posicionActual, std::list<Posicion>& OPEN, std::list<Posicion>& CLOSED, std::list<Tile> Tablero)
{
    int currentX = posicionActual.getPosicionX();
    int currentY = posicionActual.getPosicionY();
    int movimiento = posicionActual.checkMovimiento(Tablero);
    int flagClosed = 0;

    Posicion nuevaPosicion;
    Moverse moverseNorte;
    moverseNorte.setMovimientoX(0);
    moverseNorte.setMovimientoY(1);
    moverseNorte.setMovimiento(movimiento);
    moverseNorte.mover(currentX, currentY, Tablero, &nuevaPosicion);
    if(&nuevaPosicion != 0){
        for (std::list<Posicion>::iterator it=CLOSED.begin(); it != CLOSED.end(); ++it)
        {
            if((it->getPosicionX() == nuevaPosicion.getPosicionX()) && (it->getPosicionY() == nuevaPosicion.getPosicionY())) flagClosed = 1;
        }
        for (std::list<Posicion>::iterator it=OPEN.begin(); it != OPEN.end(); ++it)
        {
            if((it->getPosicionX() == nuevaPosicion.getPosicionX()) && (it->getPosicionY() == nuevaPosicion.getPosicionY())) flagClosed = 1;
        }
        if(!flagClosed) OPEN.push_back(nuevaPosicion);
        flagClosed = 0;
    }

    Moverse moverseNoreste;
    moverseNoreste.setMovimientoX(1);
    moverseNoreste.setMovimientoY(1);
    moverseNoreste.setMovimiento(movimiento);
    moverseNoreste.mover(currentX, currentY, Tablero, &nuevaPosicion);
    if(&nuevaPosicion != 0){
        for (std::list<Posicion>::iterator it=CLOSED.begin(); it != CLOSED.end(); ++it)
        {
            if((it->getPosicionX() == nuevaPosicion.getPosicionX()) && (it->getPosicionY() == nuevaPosicion.getPosicionY())) flagClosed = 1;
        }
        for (std::list<Posicion>::iterator it=OPEN.begin(); it != OPEN.end(); ++it)
        {
            if((it->getPosicionX() == nuevaPosicion.getPosicionX()) && (it->getPosicionY() == nuevaPosicion.getPosicionY())) flagClosed = 1;
        }
        if(!flagClosed) OPEN.push_back(nuevaPosicion);
        flagClosed = 0;
    }


    Moverse moverseEste;
    moverseEste.setMovimientoX(1);
    moverseEste.setMovimientoY(0);
    moverseEste.setMovimiento(movimiento);
    moverseEste.mover(currentX, currentY, Tablero, &nuevaPosicion);
    if(&nuevaPosicion != 0){
        for (std::list<Posicion>::iterator it=CLOSED.begin(); it != CLOSED.end(); ++it)
        {
            if((it->getPosicionX() == nuevaPosicion.getPosicionX()) && (it->getPosicionY() == nuevaPosicion.getPosicionY())) flagClosed = 1;
        }
        for (std::list<Posicion>::iterator it=OPEN.begin(); it != OPEN.end(); ++it)
        {
            if((it->getPosicionX() == nuevaPosicion.getPosicionX()) && (it->getPosicionY() == nuevaPosicion.getPosicionY())) flagClosed = 1;
        }
        if(!flagClosed) OPEN.push_back(nuevaPosicion);
        flagClosed = 0;
    }

    Moverse moverseSudeste;
    moverseSudeste.setMovimientoX(1);
    moverseSudeste.setMovimientoY(-1);
    moverseSudeste.setMovimiento(movimiento);
    moverseSudeste.mover(currentX, currentY, Tablero, &nuevaPosicion);
    if(&nuevaPosicion != 0){
        for (std::list<Posicion>::iterator it=CLOSED.begin(); it != CLOSED.end(); ++it)
        {
            if((it->getPosicionX() == nuevaPosicion.getPosicionX()) && (it->getPosicionY() == nuevaPosicion.getPosicionY())) flagClosed = 1;
        }
        for (std::list<Posicion>::iterator it=OPEN.begin(); it != OPEN.end(); ++it)
        {
            if((it->getPosicionX() == nuevaPosicion.getPosicionX()) && (it->getPosicionY() == nuevaPosicion.getPosicionY())) flagClosed = 1;
        }
        if(!flagClosed) OPEN.push_back(nuevaPosicion);
        flagClosed = 0;
    }

    Moverse moverseSur;
    moverseSur.setMovimientoX(0);
    moverseSur.setMovimientoY(-1);
    moverseSur.setMovimiento(movimiento);
    moverseSur.mover(currentX, currentY, Tablero, &nuevaPosicion);
    if(&nuevaPosicion != 0){
        for (std::list<Posicion>::iterator it=CLOSED.begin(); it != CLOSED.end(); ++it)
        {
            if((it->getPosicionX() == nuevaPosicion.getPosicionX()) && (it->getPosicionY() == nuevaPosicion.getPosicionY())) flagClosed = 1;
        }
        for (std::list<Posicion>::iterator it=OPEN.begin(); it != OPEN.end(); ++it)
        {
            if((it->getPosicionX() == nuevaPosicion.getPosicionX()) && (it->getPosicionY() == nuevaPosicion.getPosicionY())) flagClosed = 1;
        }
        if(!flagClosed) OPEN.push_back(nuevaPosicion);
        flagClosed = 0;
    }

   Moverse moverseSuroeste;
    moverseSuroeste.setMovimientoX(-1);
    moverseSuroeste.setMovimientoY(-1);
    moverseSuroeste.setMovimiento(movimiento);
    moverseSuroeste.mover(currentX, currentY, Tablero, &nuevaPosicion);
    if(&nuevaPosicion != 0){
        for (std::list<Posicion>::iterator it=CLOSED.begin(); it != CLOSED.end(); ++it)
        {
            if((it->getPosicionX() == nuevaPosicion.getPosicionX()) && (it->getPosicionY() == nuevaPosicion.getPosicionY())) flagClosed = 1;
        }
        for (std::list<Posicion>::iterator it=OPEN.begin(); it != OPEN.end(); ++it)
        {
            if((it->getPosicionX() == nuevaPosicion.getPosicionX()) && (it->getPosicionY() == nuevaPosicion.getPosicionY())) flagClosed = 1;
        }
        if(!flagClosed) OPEN.push_back(nuevaPosicion);
        flagClosed = 0;
    }


    Moverse moverseOeste;
    moverseOeste.setMovimientoX(-1);
    moverseOeste.setMovimientoY(0);
    moverseOeste.setMovimiento(movimiento);
    moverseOeste.mover(currentX, currentY, Tablero, &nuevaPosicion);
    if(&nuevaPosicion != 0){
        for (std::list<Posicion>::iterator it=CLOSED.begin(); it != CLOSED.end(); ++it)
        {
            if((it->getPosicionX() == nuevaPosicion.getPosicionX()) && (it->getPosicionY() == nuevaPosicion.getPosicionY())) flagClosed = 1;
        }
        for (std::list<Posicion>::iterator it=OPEN.begin(); it != OPEN.end(); ++it)
        {
            if((it->getPosicionX() == nuevaPosicion.getPosicionX()) && (it->getPosicionY() == nuevaPosicion.getPosicionY())) flagClosed = 1;
        }
        if(!flagClosed) OPEN.push_back(nuevaPosicion);
        flagClosed = 0;
    }

    Moverse moverseNoroeste;
    moverseNoroeste.setMovimientoX(0);
    moverseNoroeste.setMovimientoY(1);
    moverseNoroeste.setMovimiento(movimiento);
    moverseNoroeste.mover(currentX, currentY, Tablero, &nuevaPosicion);
    if(&nuevaPosicion != 0){
        for (std::list<Posicion>::iterator it=CLOSED.begin(); it != CLOSED.end(); ++it)
        {
            if((it->getPosicionX() == nuevaPosicion.getPosicionX()) && (it->getPosicionY() == nuevaPosicion.getPosicionY())) flagClosed = 1;
        }
        for (std::list<Posicion>::iterator it=OPEN.begin(); it != OPEN.end(); ++it)
        {
            if((it->getPosicionX() == nuevaPosicion.getPosicionX()) && (it->getPosicionY() == nuevaPosicion.getPosicionY())) flagClosed = 1;
        }
        if(!flagClosed) OPEN.push_back(nuevaPosicion);
    }

}


