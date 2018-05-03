
#ifndef FIGURA_H
#define FIGURA_H




class Figura{
 private:

float pos[3];
float rot[2];


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




