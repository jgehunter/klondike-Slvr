/**********************************************************************;
* Nombre del fichero        : Personaje.cpp
*
* Autores                   : Jorge Hunter, Inaki Echevarria, Jose Miguel Hervas
*
* Finalidad                 : Clase hija de Figura que representa un pollo
*
**********************************************************************/

#include "Personaje.h"
#include <string.h>
#include "GLstuff.h"


Personaje::Personaje(){
    personaje_rot=0;

};

void Personaje::draw()
{
    float x=pos[0];
    float y=pos[1];
    float z=pos[2];

    static float s=0;
    float osc=0;

    s+=0.2;
    z = 0.3*sin(s);
    osc = sin(3*s);
    if (s>3.14) {s=0;}


glPushMatrix();

    glTranslatef(x,y,0);

    glColor3f(128/255.0, 64/255.0, 0.0);
    glutWireTorus(0.10,0.15,15,15);
    glColor3f(1.0f, 1.0f, 0.0f);


    //Rotar y botar
    glTranslatef(0,0,z);
    glRotatef(90,1,0,0);
    glRotatef(personaje_rot,0,1,0);
    glRotatef(0,0,0,1);

    // Draw Body
    //  glTranslatef(1.0 ,1.0, 1.0);
    glutSolidSphere(0.15f,20,20);


    // Draw Head
    glTranslatef(0.0f, 0.15f+0.04f, 0.0f);
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
    glColor3f(1.0f, 160.0/255.0 , 77.0/255.0);
    glRotatef(0.0f,1.0f, 0.0f, 0.0f);
    glutSolidCone(0.03f,0.15f,10,2);


    //Alas

    glTranslatef(0.0f,-0.2f,-0.05f);
    glScalef(0.2, 0.2, 0.2);
    glColor3f( 255/255.0, 153/255.0, 51/255.0);

    glBegin(GL_POLYGON);
    glColor3f( 255/255.0, 153/255.0, 51/255.0);
    glVertex3f(0.39,0.4,0.5);
    glVertex3f(-0.39,0.4,0.5);
    glVertex3f(-1.1,-0.2*osc,-0.2);
    glVertex3f(1.1,-0.2*osc,-0.2);
    glEnd();
    glPopMatrix();


glPopMatrix();

}

