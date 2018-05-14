#include "Figura.h"
#include "nodo.h"
#include <vector>
#include <tuple>

#ifndef CAMINO_H
#define CAMINO_H



class Camino: public Figura {
 private:
    float Xact;
    float Yact;
    float Xsig;
    float Ysig;

    std::vector<std::tuple<float,float,float>> opcionesColores;
    std::tuple<float,float,float> colorElegido;

 protected:

 public:
    Camino();
    void draw();
    void siguientes(float, float);
    void elegirColor();
};

#endif
