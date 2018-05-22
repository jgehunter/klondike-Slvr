/**********************************************************************;
* Nombre del fichero        : Figura.cpp
*
* Autores                   : Jorge Hunter, Inaki Echevarria, Jose Miguel Hervas
*
* Finalidad                 : Clase que representa una figura geometriica cualquiera
*
**********************************************************************/

#include "Figura.h"
#include <string.h>
#include <iostream>

using namespace std;

Figura::Figura()
{

    pos[0]=0;
    pos[1]=0;
    pos[2]=0;

}


void Figura::mover(float x,float y,float z)
{

    pos[0]=x;
    pos[1]=y;
    pos[2]=z;

    }







