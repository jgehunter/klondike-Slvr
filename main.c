//programa principal (contiene el bucle infinito que dibuja)


#include "GLUT/glut.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "GLstuff.h"




// Prototipos de funciones 

//Callbacks de logica del programa
void myLogic();

//Callback de dibujo
void OnDibuja(void);	

//Callback de gestión del teclado
void OnKeyboardDown(unsigned char key, int x, int y);


// Ejemplo de objeto 3D
void drawSnowMan(float x, float y, float z);
  

// Variables globales


double xp=0;
double yp=0;
double zp=0;



// Texture datas tructure
GLuint KLtexture;



float snowman_rot = 0;



//Main  -> inicializaciones + bucle infinito
int main(int argc,char* argv[])
{

    
    //INICIACION PROGRAMA HUNTER
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
/**************************************************************/
  // Inicializaciones OPEN GL

  // Inicialización GLUT
  glutInit(&argc, argv);

  // Inicializaciones openGL (ver GLstuff.c)
  init_GL_stuff();
  
  // Definición call backs de GLUT
  glutDisplayFunc(OnDibuja);
	
  glutIdleFunc(myLogic);

  glutKeyboardFunc(OnKeyboardDown);
 
  // posicciona el punto de vista 
  gluLookAt(0,-10,10,           // posicion del  ojo  
	    0.0, 0, 0.0,	// hacia que punto mira  
	    0.0, 1.0, 0.0);     // vector "UP"  (vertical positivo)

  // Carga la textura
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  KLtexture= LoadTexture(900,1074, "klondike.bmp" );
  glBindTexture (GL_TEXTURE_2D, KLtexture);
  
  // bucle del programa
  glutMainLoop();
  
  return 0;   

/**************************************************************/}
 






void myLogic()  // CONTIENE LAS ACTUALIZACIONES DEL PROGRAMA
{

    
    
// PROGRAMA DE HUNTER QUE DA LAS Xp Yp Zp , Y LAS FUNCIONES QUE TRASLADAN EL MU„ECO (esto es un bucle ya de por si)
    //ejemplo trasladar mu–eco
  
    //xp=xp+0.01;      PRUEBA A USAR teclas         w
    // yp=yp+0.01;                                a s d

    
    //Ejemplos de acciones
    
    if(xp>5) xp = 0;
   // if(yp>5) yp = 0;
    
    if(yp>5) exit(1);
    
    
  
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    snowman_rot += 2.0;
  if(snowman_rot>360) snowman_rot = 0;
  
}

/**************************************************************/

void OnDibuja(void)
{
    //Borrado de la pantalla
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
/**************************************************************/
    
    // proyeccion de las figuras     DIBUJAR


  displaytext(KLtexture);
  drawSnowMan(xp,yp,zp);
  
  
    
    
    
    
    glLoadIdentity();
/**************************************************************/
  // posicciona el punto de vista 
  gluLookAt(0,-10,10,  // posicion del  ojo  
	    0.0, 0, 0.0,		        // hacia que punto mira  
	    0.0, 1.0, 0.0);         // vector "UP"  (vertical positivo)
  
  //Al final, cambiar el buffer
  glutSwapBuffers();
  glutPostRedisplay();//se le indica que redibuje la pantalla
  /**************************************************************/
}





//OBJETOS A DIBUJAR
 


void drawSnowMan(float x, float y, float z)
{

  static float s=0;
  
  // bouncing Snowman
  s+=0.05;
  z = 0.3*sin(s);
  if (s>3.14) {s=0;}


  
  glColor3f(1.0f, 1.0f, 1.0f);

  glPushMatrix();
  
  glTranslatef(x,y,z);  //TENEMOS x y z
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


