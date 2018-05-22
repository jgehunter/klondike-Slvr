/**********************************************************************;
* Nombre del fichero        : Figura.h
*
* Autores                   : Jorge Hunter, Inaki Echevarria, Jose Miguel Hervas
*
* Finalidad                 : Clase que representa una figura geometriica cualquiera
*
**********************************************************************/

#ifndef FIGURA_H
#define FIGURA_H


class Figura{

 protected:
    float pos[3];
    float rot[2];

 public:
    Figura();
    void mover(float, float ,float);
    virtual void draw()=0;

};

#endif




