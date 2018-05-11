
#include "Camino.h"
#include <string.h>
#include "GLstuff.h"


Camino::Camino(){
  
    
};

void Camino::draw()
{
    float x=pos[0];
    float y=pos[1];
    float z=pos[2];
    glTranslatef(0.0f,-0.2f,0);

    glPushMatrix();
    
    glTranslatef(-0.25f,0,0);
   // glScalef(0.2, 0.2, 0.2);
    glColor3f( 255/255.0, 0/255.0, 0/255.0);
   
    
    glBegin(GL_POLYGON);
    glColor3f( 255/255.0, 0/255.0, 0/255.0);
    glVertex3f(0,0,0.1);
    glVertex3f(0.3,0,0.1);
    glVertex3f(0.5,2,0.1);
    glVertex3f(0.3,4.2,0.1);
    glVertex3f(0.6,2,0.1);
    glVertex3f(0,4.2,0.1);
   
    
    glEnd();
    
    
    glTranslatef(0.0f,4,0);
    
    glBegin(GL_TRIANGLES);
    
    glVertex3f(0.3f, 0, 0.1f);
    glVertex3f( 0.0f,  0.5f, 0.1f);
    glVertex3f(-0.3f, 0, 0.1f);
    
    
    glEnd();

    
    glPopMatrix();
   
  

    
    
    
    

    
    
}

