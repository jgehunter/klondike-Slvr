#ifndef MOVERSE_H_INCLUDED
#define MOVERSE_H_INCLUDED

#include "Posicion.h"
#include "Tile.h"

class Moverse
{
    public:
        Moverse();
        void setMovimientoX(int x);
        void setMovimientoY(int y);
        void setMovimiento(int mov);
        void mover(int inicialX, int inicialY, std::list<Tile> Tablero, Posicion* nuevaPosicion);

    protected:
        int movimientoX;
        int movimientoY;
        int movimiento;


};


#endif // MOVERSE_H_INCLUDED
