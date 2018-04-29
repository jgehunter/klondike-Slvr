#ifndef TILE_H_INCLUDED
#define TILE_H_INCLUDED

class Tile
{
    public:
        Tile();
        int getPosicionX();
        int getPosicionY();
        int getMovimiento();
        void setPosicionX(int x);
        void setPosicionY(int y);
        void setMovimiento(int m);

    private:
        int posicionX;
        int posicionY;
        int movimiento;
};


#endif // TILE_H_INCLUDED
