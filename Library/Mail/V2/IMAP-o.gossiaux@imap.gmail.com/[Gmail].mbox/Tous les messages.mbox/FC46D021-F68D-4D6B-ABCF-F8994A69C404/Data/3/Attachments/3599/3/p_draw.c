#include <GL/glut.h>
#include "p_draw.h"

int monChoix;
static GLfloat alpha=0.0;
static GLfloat beta=0.0;
static GLfloat lambda=0.0;
static GLfloat gamma=0.0;
static GLfloat teta=0.0;


GLboolean Move_Flag = GL_FALSE;  
GLboolean Zoom_Flag  = GL_FALSE;  

GLdouble Radius = 1.0;
GLdouble Twist = 0.0;
GLdouble Longitude = 0.0;
GLdouble Latitude = 0.0;  

int Y_Start_Zoom;  
int X_Start_Move;  
int Y_Start_Move; 

 float Rouge[4] = {1,0.0,0.0,1}; 
 float Bleu[4] = {0.0,1,0.0,1};
 float Vert[4] = {0.0,0.0,1,1};
 float AutreColor[4] = {0,0.8,0,1};
 float AutreColor1[4] = {0,2.0,0,0};
 float Blanco [4] = {1,1,1,1};
 float taille=60;
 int nbCases= 40;



void drawGrid2(int nbCases,float taille) //Grille carree de cote taille divisee en nbCases cases
{
         //Deux   boucles imbriquees qui dessinent des quadrilateres
        // glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,Tab);
          
         int nbx,nby;
         nbx=nby=nbCases;
         float xmin,xmax,ymin,ymax;
         xmax=ymax=taille;
         xmin=ymin=-taille;
         
         float x,y;
         static GLfloat blueColor[]={0.0,0.0,1.0};
         static GLfloat whiteColor[]={1.0,1.0,1.0};
         float lx=(xmax-xmin)/nbx;
         float ly=(ymax-ymin)/nby;
         int a,b;
         a=0;
     
    for(x=xmin; x<xmax;x+=lx){
                 b=a;
                 for(y=ymin;y<ymax;y+=ly){
                      b+=1;
                      if((b%2)==0)
                      {
                              //glColor3f(1.0,0.0,0.0); 
                               glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,AutreColor);
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,AutreColor);
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,AutreColor); 
                      }
                      else
                      {
                          //glColor3f(0.0,1.0,0.0); 
                           glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,AutreColor1);
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,AutreColor1);
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,AutreColor1);
                      }
                       glBegin(GL_QUADS);
                         glVertex2f(x,y);
                         glVertex2f(x+lx,y);
                         glVertex2f(x+lx,y+ly);
                         glVertex2f(x,y+ly);
                         glEnd();
                         }   
    a+=1;
    
    }                

     
     
}
void drawVoiture()
{
     glColor3f( 255, 0.0, 0.0 );
    glBegin(GL_QUADS);

    //glColor3ub(255,0,0); //face rouge
    glVertex3d(1,1,1);
    glVertex3d(1,1,-2);
    glVertex3d(-1,1,-2);
    glVertex3d(-1,1,1);

    //glColor3ub(0,255,0); //face verte
    glVertex3d(1,-1,1);
    glVertex3d(1,-1,-2);
    glVertex3d(1,1,-2);
    glVertex3d(1,1,1);

    //glColor3ub(0,0,255); //face bleue
    glVertex3d(-1,-1,1);
    glVertex3d(-1,-1,-2);
    glVertex3d(1,-1,-2);
    glVertex3d(1,-1,1);

    //glColor3ub(255,255,0); //face jaune
    glVertex3d(-1,1,1);
    glVertex3d(-1,1,-2);
    glVertex3d(-1,-1,-2);
    glVertex3d(-1,-1,1);

    //glColor3ub(0,255,255); //face cyan
    glVertex3d(1,1,-2);
    glVertex3d(1,-1,-2);
    glVertex3d(-1,-1,-2);
    glVertex3d(-1,1,-2);

    //glColor3ub(255,0,255); //face magenta
    glVertex3d(1,-1,1);
    glVertex3d(1,1,1);
    glVertex3d(-1,1,1);
    glVertex3d(-1,-1,1);

    glEnd();

   
}
void DrawAxes(void)
{
          glColor3f( 1.0, 1.0, 0.0 );
              
          glBegin( GL_LINES );
          glVertex3f( 0.0, 0.0, 0.0);
          glVertex3f( 1.5, 0.0, 0.0);
          glVertex3f( 0.0, 0.0, 0.0);
          glVertex3f( 0.0, 1.5, 0.0);      
          glVertex3f( 0.0, 0.0, 0.0);
          glVertex3f( 0.0, 0.0, 1.5);      
          glEnd();
              
          glColor3f( 1.0, 0.0, 0.0 );
          glBegin( GL_POLYGON );
          glVertex3f( 1.5,   0.0 , 0.0);
          glVertex3f( 1.35, -0.05, 0.0);
          glVertex3f( 1.35,  0.05, 0.0);
          glEnd();
              
          glColor3f( 0.0, 1.0, 0.0 );
          glBegin( GL_POLYGON );
          glVertex3f(  0.0,  1.5 , 0.0);
          glVertex3f( -0.05, 1.35, 0.0);
          glVertex3f(  0.05, 1.35, 0.0);
          glEnd();
              
          glColor3f( 0.0, 0.0, 1.0 );
          glBegin( GL_POLYGON );
          glVertex3f(  0.0,  0.0, 1.5 );
          glVertex3f( -0.05, 0.0, 1.35);
          glVertex3f(  0.05, 0.0, 1.35);
          glEnd();
}

void Polarview ( GLdouble Radius,GLdouble Twist,GLdouble Longitude,GLdouble Latitude )
{
          glTranslated( 0.0, 0.0, -Radius );
          glRotated( -Twist,    0.0, 0.0, 1.0 );
          glRotated( -Latitude, 1.0, 0.0, 0.0 );
          glRotated( Longitude, 0.0, 1.0, 0.0 );
}

void Mousefunc ( int Button, int State, int X , int Y )
{
      switch (Button)
        {
        case GLUT_LEFT_BUTTON :
          switch (State)
    	{
    	case GLUT_DOWN :
    	  X_Start_Move = X;
    	  Y_Start_Move = Y;
    	  Move_Flag = GL_TRUE;
    	  break;
    	case GLUT_UP :
    	  Move_Flag = GL_FALSE;
    	  break;
    	}
          break;
        case GLUT_RIGHT_BUTTON :
          switch (State)
    	{
    	case GLUT_DOWN :
    	  Y_Start_Zoom = Y;
    	  Zoom_Flag = GL_TRUE;
    	  break;
    	case GLUT_UP :
    	  Zoom_Flag = GL_FALSE;
    	  break;
    	}
          break;
        case GLUT_MIDDLE_BUTTON :
          switch (State)
    	{
    	case GLUT_DOWN :
    	  break;
    	case GLUT_UP :
    	  break;
    	}
        }
}

void Mousemotionmove ( int X, int Y)
{
      Longitude = Longitude + (GLdouble)(X - X_Start_Move);
      Latitude = Latitude - (GLdouble)(Y - Y_Start_Move);
    
      X_Start_Move = X;
      Y_Start_Move = Y;
      glutPostRedisplay();
}

void Mousemotionzoom ( int X, int Y )
{
      Radius = Radius - (GLdouble)(Y - Y_Start_Zoom) / 10.0;
      Y_Start_Zoom = Y;
      glutPostRedisplay();
}
void Mousemove ( int X, int Y)
{
      if (Move_Flag)
        Mousemotionmove(X,Y);
      else
        if (Zoom_Flag)
          Mousemotionzoom(X,Y);
}


void Drawscene ( void )
{
     glEnable(GL_LIGHTING); // Eclairage permanent  
     glEnable(GL_DEPTH_TEST); //Pour effet de profondeur
     
        static GLfloat whiteColor[]={1.0,1.0,1.0};
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); //afficher le tampon d'affichage : color et profondeur
        
        glColor3fv(whiteColor);
        
        glLoadIdentity(); // On ignore tout ce qu'il y a avant
        
        //-------------Champ de vision------------
        glTranslatef(0.0,0.0,-100.0);
        
        //------Pour pouvoir bouger la camera-----
        Polarview(Radius, Twist, Longitude, Latitude);
        
        //------Grille------
        float taille=60.0;
        int nbCases=60;
        DrawGrid2();
        //drawGrid2(nbCases, tGrille);
        
        
        switch(monChoix)
        {
                case 1: drawVoiture() ; break;
                case 2: drawGrid2(200, 100);break;
                case 3: glDisable(GL_LIGHT0);break;
                case 4: glEnable(GL_LIGHT0);break;
                case 5: break;
                            
        } 
  
      
      DrawAxes();
     
  glutSwapBuffers();
}
