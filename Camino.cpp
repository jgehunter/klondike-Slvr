
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

    
    float Xact=7;
    float Yact=7;
    float Xsig=-7;
    float Ysig=-7;
    float L=0;
    float angulo=0;
  
    /* for(auto iterador : recorrido){
        std::cout << iterador.Getcoordenadas().first << iterador.Getcoordenadas().second << std::endl;
    }
    */
   

  

    
    Xsig=Xsig-Xact;
    Ysig=Ysig-Yact;
    
    //conversiones al mapa
    Xact*=0.42;
    Yact*=0.35;
    Xsig*=0.42;
    Ysig*=0.35;
   
    L=sqrtf(Xsig*Xsig+Ysig*Ysig);
  
   
    if(Xsig>=0 && Ysig>=0){ angulo=acos(Ysig/L); angulo*=(180/PI);}
    if(Xsig>=0 && Ysig<=0) {angulo=acos(Xsig/L);angulo*=(180/PI); angulo+=90;}
    if(Xsig<=0 && Ysig<=0) {angulo=acos(-Ysig/L);angulo*=(180/PI); angulo+=180;}
    if(Xsig<=0 && Ysig>=0) {angulo=acos(Xsig/L);angulo*=(180/PI); angulo+=270;}
      
        
    
    
    
    std::cout << L <<" "<<angulo << std::endl;
    
  /*  //conversiones al mapa
    Xact*=0.42;
    Yact*=0.35;
    Xsig*=0.42;
    Ysig*=0.35; */
  
    L*=0.95;
 
   std::cout << L << std::endl;
    glPushMatrix();
   
    glTranslatef(0,-0.2,0);
    // glScalef(0.2, 0.2, 0.2);
    glColor3f( 255/255.0, 0/255.0, 0/255.0);
    glTranslatef(Xact,Yact,0);
    glRotatef(-angulo,0,0,1);
   

    glScalef(0.5, 0.5, 1);
    glBegin(GL_POLYGON);
    
    glColor3f( 255/255.0, 0/255.0, 0/255.0);
    glVertex3f(0.2,0,0.1);
    glVertex3f(0.5,L,0.1);
    glVertex3f(0.2,2*L,0.1);
    glVertex3f(-0.2,2*L,0.1);
    glVertex3f(0.2,0.5+L,0.1);
    glVertex3f(-0.2,0,0.1);
    
    glEnd();
    
 
    
    glTranslatef(0.0f,2*L,0);
    glBegin(GL_TRIANGLES);
    
    glVertex3f(0.5f, 0, 0.1f);
    glVertex3f( 0.0f,  0.5f, 0.1f);
    glVertex3f(-0.5f, 0, 0.1f);
    
    glEnd();
    
   
    glPopMatrix();
    
    
    /*
    
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
   
  

    
    
    
    */

    
    
}

