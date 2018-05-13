
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

//std::cout << " Xsig = "  << Xsig << " Ysig = "  << Ysig << " Xact = "  << Xact<< " Yact = "  << Yact << std::endl;
}



void Camino::draw()

{

   float Xactdraw;
   float Yactdraw;
   float  Xsigdraw;
   float  Ysigdraw;
    
   //Para pruebas
    
    
   /* Xactdraw=-1;
    Yactdraw=-1;
    Xsigdraw=5;
    Ysigdraw=5;
   */

    
    Xactdraw=Xact;
    Yactdraw=Yact;
    Xsigdraw=Xsig;
    Ysigdraw=Ysig;

    
    float L=0;
    float angulo=0;
 
    if(Xactdraw!=0 && Yactdraw!=0) {
        
        if(Xsigdraw-Xactdraw>=0) Xsigdraw=Xsigdraw-Xactdraw+1;
            else Xsigdraw=Xsigdraw-Xactdraw-1;
        
        if(Ysigdraw-Yactdraw>=0) Ysigdraw=Ysigdraw-Yactdraw+1;
            else Ysigdraw=Ysigdraw-Yactdraw-1;
        }
    else { Xsigdraw=Xsigdraw-Xactdraw; Ysigdraw=Ysigdraw-Yactdraw;}
    
    //conversiones al mapa
    Xsigdraw*=0.42;
    Ysigdraw*=0.35;
    Xactdraw*=0.42;
    Yactdraw*=0.35;
    
    L=sqrtf(Xsigdraw*Xsigdraw+Ysigdraw*Ysigdraw);
  
   //Obtencion del ángulo
    if(Xsigdraw>=0 && Ysigdraw>=0) {angulo=acos(Ysigdraw/L); angulo*=(180/PI); }
    if(Xsigdraw>=0 && Ysigdraw<=0) {angulo=acos(Xsigdraw/L); angulo*=(180/PI); angulo+=90;}
    if(Xsigdraw<=0 && Ysigdraw<=0) {angulo=acos(-Ysigdraw/L);angulo*=(180/PI); angulo+=180;}
    if(Xsigdraw<=0 && Ysigdraw>=0) {angulo=acos(Xsigdraw/L); angulo*=(180/PI); angulo+=270;}
      
        
   
    
    
    
    //Dibujo flecha

    L*=0.8;
 
    //std::cout<< L << std::endl;
    glPushMatrix();
   
    
    glTranslatef(Xactdraw,Yactdraw,0);
  
    glColor3f( 255/255.0, 0/255.0, 0/255.0);
    glTranslatef(0,-0.2,0);
    glRotatef(-angulo,0,0,1);
   
    glScalef(0.5, 0.5, 1);
   
    glBegin(GL_POLYGON);
    glColor3f( 255/255.0, 0/255.0, 0/255.0);
    
    glVertex3f(-0.1,0,0.01);
    glVertex3f(0.2,0,0.01);
    glVertex3f(0.21*L,L,0.05*L);
    glVertex3f(0.21*L-0.2,L,0.05*L);
    glEnd();
    
   
    glBegin(GL_POLYGON);
    glColor3f( 255/255.0, 0/255.0, 0/255.0);
    
    glVertex3f(0.21*L-0.2,L,0.05*L);
    glVertex3f(0.21*L,L,0.05*L);
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

