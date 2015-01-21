#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include "p_draw.h"


extern int monChoix;
float Blanc [4] = {1,1,1,1};
// méthode d'une variable virtuelle pour faire passer le choix

void Resize ( int Width, int Height );


void Initialize (int Width,int Height) 
{
 
 
  glClearColor( 1.0, 1.0, 1.0, 1.0 ); //couleur de derrière

  glMatrixMode(GL_PROJECTION);// dans laquelle nous définissons le mode de projection (orthogonale, perspective)
  
  //Lumiere (x3 =specular, ambient et diffuse)
   glLightfv(GL_FRONT_AND_BACK, GL_SPECULAR,Blanc);
   glLightfv(GL_FRONT_AND_BACK, GL_AMBIENT,Blanc);
   glLightfv(GL_FRONT_AND_BACK, GL_DIFFUSE,Blanc);
  
  //Appel de la fonction Resize
  Resize(Width , Height);
 
  glMatrixMode(GL_MODELVIEW);//pour positionner les objets dans la scène
  
}

void Resize ( int Width, int Height )
{  
  
GLdouble Aspect;  
   
  glViewport(0, 0, (GLsizei)Width, (GLsizei)Height);

  Aspect = (GLdouble)Width / (GLdouble)Height;

  glMatrixMode( GL_PROJECTION );

  glLoadIdentity();
  gluPerspective( 45.0, Aspect, 10.0, 200.0);
 
  glMatrixMode( GL_MODELVIEW);
}
   
void Keyfunc ( unsigned char Key, int X, int Y) // pour ecrire dans la console
{
  switch (Key)
    {
    case 'f' :
      printf("f\n");
      break;
    case 's' :
      printf("s\n");
      break;
    case 'a' :
      printf("Bienvenue !!!\n");
      break;
    }
}





void Menu ( int Value ) 
{
  if (Value == 1)
     {
            monChoix=1;
     }              
    
  else
    if (Value == 2)
     {
            monChoix=2;
     }
    else
      if (Value == 3)
	{
            monChoix=3;
     }
    else
      if (Value == 4)
	{
            monChoix=4;
     }
    else
      if (Value == 5)
	{
            monChoix=5;
     }
      else
	if ( Value == 666)
	  exit (0);
}


     
int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE |GLUT_DEPTH);
  glutCreateWindow("OpenGL & Glut: Programme de base");

  glutDisplayFunc(Drawscene);
  glutReshapeFunc(Resize);
  glutKeyboardFunc(Keyfunc);

  Initialize(200,200); // ?

 ///////pour la souris : 
  glutMouseFunc(Mousefunc);
  glutMotionFunc(Mousemove);
  
  glutCreateMenu(Menu);
  glutAddMenuEntry("Voiture", 1);
  glutAddMenuEntry("--------", 0);
  glutAddMenuEntry("Grille", 2);
  glutAddMenuEntry("--------", 0);
  glutAddMenuEntry("off", 3);
  glutAddMenuEntry("--------", 0);
  glutAddMenuEntry("on", 4);
  glutAddMenuEntry("--------", 0);
  glutAddMenuEntry("Vide", 5);
  glutAddMenuEntry("--------", 0);
  glutAddMenuEntry("Quit", 666);
  glutAttachMenu(GLUT_MIDDLE_BUTTON);

  glutIdleFunc(Drawscene); // fonction à executer quand il n'y a rien à faire
  glutMainLoop(); // boucle infinie
  return 0;
}
