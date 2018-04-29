#include <iostream>
#include <map>
#include <fstream>
#include <list>
#include "Tile.h"
#include "Posicion.h"
#include "sig.h"
#include "Moverse.h"

using namespace std;

int main()
{
    std::list<Tile> Tablero;
    std::ifstream fichero("Tablero.txt");
    int posX;
    int posY;
    int mov;
    while( fichero >> posX >> posY >> mov )
    {
        Tile nuevaCasilla;
        nuevaCasilla.setPosicionX( posX );
        nuevaCasilla.setPosicionY( posY );
        nuevaCasilla.setMovimiento( mov );

        Tablero.push_front(nuevaCasilla);

    }

    /* for( std::list<Tile>::iterator it = Tablero.begin(); it != Tablero.end(); ++it ) {
        std::cout << it-> getPosicionX() << " " << it-> getPosicionY() << " " << it -> getMovimiento() << std::endl;
    } */

    std::list<Posicion> OPEN;
    std::list<Posicion> CLOSED;

    Posicion inicio;
    Posicion currentPosition;
    inicio.setPosicionX(0);
    inicio.setPosicionY(0);
    currentPosition = inicio;
    int flagFinished = 0;

    std::cout << "Valor de movimiento: " << currentPosition.checkMovimiento(Tablero) << std::endl;

    OPEN.push_back(inicio);

    std::cout << "Tamaño de open:" << " " << OPEN.size() << std::endl;

    while( !OPEN.empty() && flagFinished == 0 )
    {
        if(currentPosition.checkMovimiento(Tablero) == 0)
        {
            flagFinished = 1;
        }
        if(!flagFinished) {
        std::cout << "Tamaño de open:" << " " << OPEN.size() << std::endl;
        std::cout << "Tamaño de closed:" << " " << CLOSED.size() << std::endl;
        sig(currentPosition, OPEN, CLOSED, Tablero);
        CLOSED.push_front(currentPosition);
        OPEN.pop_front();
        currentPosition = OPEN.front();
        std::cout << "posicion x,y: " << currentPosition.getPosicionX() << " " << currentPosition.getPosicionY() << std::endl;
        }
    }

    std::cout << "La posicion final es: " << currentPosition.getPosicionX() << " " << currentPosition.getPosicionY() << std::endl;


    return 0;
}
