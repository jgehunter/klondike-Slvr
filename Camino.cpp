
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
   


    
    glTranslatef(0.0f,-0.2f,-0.05f);
    glScalef(0.2, 0.2, 0.2);
    glColor3f( 255/255.0, 153/255.0, 51/255.0);
    
    glBegin(GL_POLYGON);
    glColor3f( 255/255.0, 153/255.0, 51/255.0);
    glVertex3f(0.39,0.4,0.5);
    glVertex3f(-0.39,0.4,0.5);
    glVertex3f(-1,-0.1,-0.2);
    glVertex3f(1,-0.1,-0.2);
    glEnd();

    
    glPopMatrix();
   
  
glPopMatrix();
    
    
    
    

    
    
}

