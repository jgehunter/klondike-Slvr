#include "Figura.h"
#include "nodo.h"
#include <vector>

#ifndef CAMINO_H
#define CAMINO_H



class Camino: public Figura {
 private:
    float Xact;
    float Yact;
    float Xsig;
    float Ysig;

 protected:
  
 public:
    Camino();
    //void drawsolution(std::vector<Nodo>);
    void draw();
    void siguientes(float, float);
};

#endif
