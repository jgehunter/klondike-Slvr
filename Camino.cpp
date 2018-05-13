
#include "Camino.h"
#include <string.h>
#include "GLstuff.h"
#include "nodo.h"
#include <vector>
#include <iostream>
#define PI 3.1415926535897932384626433832795

Camino::Camino(){
    Xact=0;
    Yact=0;
    Xsig=0;
    Ysig=0;
    
};

void Camino::siguientes(float x, float y){
    Xact=Xsig;
    Yact=Ysig;
    
    Xsig=x;
    Ysig=y;
}



void Camino::draw()
//void Camino::drawsolution(std::vector<Nodo> recorrido)
{

    
   /* float Xact=0;
    float Yact=0;
    float Xsig=4;
    float Ysig=7;*/
    
    
    float L=0;
    float angulo=0;

   
    
   
    Xsig=Xsig-Xact;
    Ysig=Ysig-Yact;
    
    //conversiones al mapa
    Xact*=0.42;
    Yact*=0.35;
    Xsig*=0.42;
    Ysig*=0.35;
   
    L=sqrtf(Xsig*Xsig+Ysig*Ysig);
  
   //Obtencion del ángulo
    if(Xsig>=0 && Ysig>=0){ angulo=acos(Ysig/L); angulo*=(180/PI);}
    if(Xsig>=0 && Ysig<=0) {angulo=acos(Xsig/L);angulo*=(180/PI); angulo+=90;}
    if(Xsig<=0 && Ysig<=0) {angulo=acos(-Ysig/L);angulo*=(180/PI); angulo+=180;}
    if(Xsig<=0 && Ysig>=0) {angulo=acos(Xsig/L);angulo*=(180/PI); angulo+=270;}
      
        
    
    
    
    //Dibujo flecha

    L*=0.95;
 
  
    glPushMatrix();
   
    glTranslatef(0,-0.2,0);
   
    glColor3f( 255/255.0, 0/255.0, 0/255.0);
    glTranslatef(Xact,Yact,0);
    glRotatef(-angulo,0,0,1);
   

    glScalef(0.5, 0.5, 1);
    glBegin(GL_POLYGON);
    
    glColor3f( 255/255.0, 0/255.0, 0/255.0);
    glVertex3f(0.2,0,0.05);
    glVertex3f(0.5,L,0.1);
    glVertex3f(0.2,2*L,0.15);
    glVertex3f(-0.2,2*L,0.15);
    glVertex3f(0.2,0.5+L,0.1);
    glVertex3f(-0.2,0,0.05);
    

    
    glEnd();
    
 
    
    glTranslatef(0.0f,2*L,0);
    glBegin(GL_TRIANGLES);
    
    glVertex3f(0.5f, 0, 0.15f);
    glVertex3f( 0.0f,  0.5f, 0.2f);
    glVertex3f(-0.5f, 0, 0.15f);
    
    glEnd();
    
   
    glPopMatrix();
    
    
    
    
}

