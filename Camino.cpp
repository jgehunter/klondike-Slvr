
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

std::cout << " Xsig = "  << Xsig << " Ysig = "  << Ysig << " Xact = "  << Xact<< " Yact = "  << Yact << std::endl;
}



void Camino::draw()

{

   float Xactdraw;
   float Yactdraw;
   float  Xsigdraw;
   float  Ysigdraw;
    
    Xactdraw=-3;
    Yactdraw=-3;
    Xsigdraw=-7;
    Ysigdraw=-7;
/*
 Xactdraw=Xact;
 Yactdraw=Yact;
 Xsigdraw=Xsig;
 Ysigdraw=Ysig;
  */
    
    float L=0;
    float angulo=0;

   
    
   
    Xsigdraw=Xsigdraw-Xactdraw;
    Ysigdraw=Ysigdraw-Yactdraw;
    
    //conversiones al mapa
    Xsigdraw*=0.42;
    Ysigdraw*=0.35;
   
    L=sqrtf(Xsigdraw*Xsigdraw+Ysigdraw*Ysigdraw);
  
   //Obtencion del ángulo
    if(Xsigdraw>=0 && Ysigdraw>=0){
        angulo=acos(Ysigdraw/L);
        angulo*=(180/PI);
        Xactdraw=0.42*(Xactdraw+1);
        Yactdraw=0.35*(Yactdraw+1);
        }
  
    if(Xsigdraw>=0 && Ysigdraw<=0){
        angulo=acos(Xsigdraw/L);
        angulo*=(180/PI);
        angulo+=90;
        Xactdraw=0.42*(Xactdraw+1);
        Yactdraw=0.35*(Yactdraw+1);
        }
  
    if(Xsigdraw<=0 && Ysigdraw<=0){
        angulo=acos(-Ysigdraw/L);
        angulo*=(180/PI);
        angulo+=180;
        Xactdraw=0.42*(Xactdraw+1);
        Yactdraw=0.35*(Yactdraw+1);
        }
    
    if(Xsigdraw<=0 && Ysigdraw>=0){
        angulo=acos(Xsigdraw/L);
        angulo*=(180/PI);
        angulo+=270;
        Xactdraw=0.42*(Xactdraw+1);
        Yactdraw=0.35*(Yactdraw+1);
        }
      
        
    Xactdraw=0.42*(Xactdraw+1); Yactdraw=0.35*(Yactdraw+1);
    
    
    //Dibujo flecha

    L*=0.8;
 
    std::cout<< L << std::endl;
    glPushMatrix();
   
    glTranslatef(0,0.1,0);
   
   
    glColor3f( 255/255.0, 0/255.0, 0/255.0);
    glTranslatef(Xactdraw,Yactdraw,0);
    glRotatef(-angulo,0,0,1);
   

    glScalef(0.5, 0.5, 1);
   
    glBegin(GL_POLYGON);
    glColor3f( 255/255.0, 0/255.0, 0/255.0);
    
    glVertex3f(-0.1,0,0.01);
    glVertex3f(0.2,0,0.01);
    glVertex3f(0.16*L,L,0.15);
    glVertex3f(0.16*L-0.2,L,0.15);
    glEnd();
    
   
    glBegin(GL_POLYGON);
    glColor3f( 255/255.0, 0/255.0, 0/255.0);
    
    glVertex3f(0.16*L-0.2,L,0.15);
    glVertex3f(0.16*L,L,0.15);
    glVertex3f(0.1,2*L,0.1);
    glVertex3f(-0.1,2*L,0.1);
    glEnd();
 
    
    glTranslatef(0.0f,2*L,0);
    glBegin(GL_TRIANGLES);
    
    glVertex3f(0.4f, 0, 0.1f);
    glVertex3f( 0.0f,  0.4f, 0.01f);
    glVertex3f(-0.4f, 0, 0.1f);
    
    glEnd();
    
   
    glPopMatrix();
    
    
    
    
}

