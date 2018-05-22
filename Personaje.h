/**********************************************************************;
* Nombre del fichero        : Personaje.cpp
*
* Autores                   : Jorge Hunter, Inaki Echevarria, Jose Miguel Hervas
*
* Finalidad                 : Clase hija de Figura que representa un pollo
*
**********************************************************************/

#include "Figura.h"

#ifndef PERSONAJE_H
#define PERSONAJE_H


class Personaje: public Figura {

 public:
    Personaje();
    void draw();
    float personaje_rot;

};

#endif
