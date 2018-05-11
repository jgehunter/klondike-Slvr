
#include "Camino.h"
#include <string.h>
#include "GLstuff.h"
#include "nodo.h"
#include <vector>
#include <iostream>
#define PI 3.1415926535897932384626433832795

Camino::Camino(){
  
    
};
void Camino::draw()
//void Camino::draw(std::vector<Nodo> recorrido)
{

    
    int Xact=5;
    int Yact=3;
    int Xsig=4;
    int Ysig=-3;
    float angulo=0;
    float L;
    
   /* for(auto iterador : recorrido){
        std::cout << iterador.Getcoordenadas().first << iterador.Getcoordenadas().second << std::endl;
    }
    */
   

  
    Xsig=Xsig-Xact;
    Ysig=Ysig-Yact;
    
    
    glTranslatef(0.1f+0.42*Xact,-0.3f+0.35*Yact,0);
    L=sqrtf(Xsig*Xsig+Ysig*Ysig);
    
    angulo=acos(Xsig/L);
    
    if(Xsig<0) angulo=acos(Xsig/L);
    
    if(Ysig<0) angulo=asin(Ysig/L);
   
    angulo*=(180/PI);
    
    glRotatef(-angulo,0,0,1);

std::cout << L <<" "<<angulo << std::endl;
   
   
    
    
    glPushMatrix();
    
    glTranslatef(-0.1f,0,0);
   // glScalef(0.2, 0.2, 0.2);
    glColor3f( 255/255.0, 0/255.0, 0/255.0);
   
   
      glScalef(0.5, 0.5, 1);
    glBegin(GL_POLYGON);
  
    glColor3f( 255/255.0, 0/255.0, 0/255.0);
    glVertex3f(0.2,0,0.1);
    glVertex3f(0.5,2,0.1);
    glVertex3f(0.2,4.2,0.1);
    glVertex3f(-0.2,4.2,0.1);
    glVertex3f(0.2,3,0.1);
    glVertex3f(-0.2,0,0.1);
   
    glEnd();
    
    
    
    glTranslatef(0.0f,4,0);
    glBegin(GL_TRIANGLES);
    
    glVertex3f(0.5f, 0, 0.1f);
    glVertex3f( 0.0f,  0.5f, 0.1f);
    glVertex3f(-0.5f, 0, 0.1f);
    
    glEnd();

    
    glPopMatrix();
   
  

    
    
    
    

    
    
}

