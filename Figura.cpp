
#include "Figura.h"
#include <string.h>
#include <iostream>

using namespace std;




//INICIALIZAR

Figura::Figura() {

    pos[0]=0;
    pos[1]=0;
    pos[2]=0;

}


/*void Figura::getNombre(char *n)
{
  strcpy(n,nombre);
}


void Figura::setNombre(char *n)
{
  strcpy(nombre,n);
}

*/
void Figura::mover(float x,float y,float z)
{
  
    pos[0]=x;
    pos[1]=y;
    pos[2]=z;

    }
void Figura::rotar(float a, float[])
{
   
    
    
}

    

  

