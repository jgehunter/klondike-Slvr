
#ifndef Figura
#define Figura

#include "Personaje.h"


class Figura{
 private:
pos= float[3];
rot= float[2];


 public:
  Figura();
  
    
    void getNombre(char *n);
    void setNombre(char *n);
 // void addFigura(Figura*);
    void mover(float, float ,float);
    void rotar (float,float[3]);
    virtual void draw()=0;
};

#endif




