
#include "Personaje.h"
#include <string.h>
#include "GLstuff.h"

void Personaje::draw()
{
    float x=Personaje.pos[0];
    float y=Personaje.pos[1];
    float z=Personaje.pos[2];
   
    static float s=0;
    
    // bouncing Snowman
    s+=0.05;
    z = 0.3*sin(s);
    if (s>3.14) {s=0;}
    
    
    
    glColor3f(1.0f, 1.0f, 1.0f);
    
    glPushMatrix();
    
    glTranslatef(x,y,z);  
    glRotatef(90,1,0,0);
    glRotatef(snowman_rot,0,1,0);
    glRotatef(0,0,0,1);
    
    
    // Draw Body
    //  glTranslatef(1.0 ,1.0, 1.0);
    glutSolidSphere(0.15f,20,20);
    
    
    // Draw Head
    glTranslatef(0.0f, 0.15f+0.08f, 0.0f);
    glutSolidSphere(0.08f,20,20);
    
    // Draw Eyes
    glPushMatrix();
    glColor3f(0.0f,0.0f,0.0f);
    glTranslatef(0.015f, 0.06f, 0.08f);
    glutSolidSphere(0.015f,10,10);
    glTranslatef(-0.03f, 0.0f, 0.0f);
    glutSolidSphere(0.015f,10,10);
    glPopMatrix();
    
    // Draw Nose
    glColor3f(1.0f, 0.5f , 0.5f);
    glRotatef(0.0f,1.0f, 0.0f, 0.0f);
    glutSolidCone(0.03f,0.15f,10,2);
    glPopMatrix();
    
    
}

