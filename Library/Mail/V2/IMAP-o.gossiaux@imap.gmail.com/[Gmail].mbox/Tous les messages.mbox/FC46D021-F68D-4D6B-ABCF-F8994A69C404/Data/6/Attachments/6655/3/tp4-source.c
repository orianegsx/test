#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* ********************************************** */
/* variable globales */
/* ********************************************** */

typedef struct element  /* struture */
{
  char name[10] ;
  struct element *suiv ;
} liste ;

char s[10] ;  /* chaine de caractere saisie au clavier */
liste *fin, *deb, *cou ; /* trois pointeurs : fin, debu et courant */


/* ********************************************** */
/* fonction
/* ********************************************** */

int arretProg() ;
int menu();
int exemple () ;
int ajoutTete() ;
int insertion(int position);
int suppressionTete() ;
int listing();
int acces(int position) ;


/* ********************************************** */
/* main() */
/* ********************************************** */

int main()
{
    menu();
    return(0) ;
}


/* ********************************************** */
/* exemple()
/* ********************************************** */

int exemple ()
{
  if ( (fin = (liste*) malloc (sizeof(liste))) == NULL ) arretProg();
  deb = fin ;

  printf("\n\nentrer un 1er mot : ");
  scanf("%s",s);
  strcpy(fin->name, s);
  if ( (fin->suiv = (liste*) malloc (sizeof(liste))) == NULL ) arretProg() ;
  fin = fin->suiv ;
  
  printf("entrer un 2eme mot : ");
  scanf("%s",s);
  strcpy(fin->name, s);
  if ( (fin->suiv = (liste*) malloc (sizeof(liste))) == NULL ) arretProg() ;
  fin = fin->suiv ;
  
  printf("entrer un 3eme mot : ");
  scanf("%s",s);
  strcpy(fin->name, s);
  if ( (fin->suiv = (liste*) malloc (sizeof(liste))) == NULL ) arretProg() ;
  fin = fin->suiv ;
  
  printf("entrer un dernier mot : ");
  scanf("%s",s);
  strcpy(fin->name, s);
  fin->suiv = NULL ;
  
  printf("\n\nListing : ");
  for (cou=deb ; cou!=NULL ; cou=cou->suiv)
   printf("%s",cou->name) ;

  printf("\n\n");
  system("PAUSE") ;
  return(0);
}


/* ********************************************** */
/* arret du programme */
/* ********************************************** */

int arretProg()
{
    printf("Arret du programme\n");
    printf("Plus de place en memoire pour allouer un nouveau pointeur\n");
    system("PAUSE") ;
    exit(1);
}

/* ********************************************** */
/* menu */
/* ********************************************** */

int menu() 
{
  char c ;
  do
  {
    system("CLS");
    printf("******\n MENU\n******\n\n");
    printf(" 0. Quitter le programme\n");
    printf(" 1. Exemple (4 ajouts en queue et listing) \n");
    printf(" 2. Ajout en tete de liste\n");
    printf(" 3. Insertion (indiquer la position)\n");
    printf(" 4. Suppression en tete de liste\n");
    printf(" 5. Listing\n\n");
    printf("Votre choix (0 a 5) ? : ") ;
    c=getche() ;
    switch (c) 
    {
        case '1' : exemple() ; break ;        
    }    
  }  
  while ( c != '0');
  return(0) ;
}

/* ********************************************** */
/* ajoutTete */
/* ********************************************** */
int ajoutTete() 
{

  return (0) ;
}

/* ********************************************** */
/* insertion */
/* ********************************************** */
int insertion(int position)
{

  return (0) ;
}


/* ********************************************** */
/* suppressionTete */
/* ********************************************** */
int suppressionTete()
{

  return (0) ;
}


/* ********************************************** */
/* listing */
/* ********************************************** */
int listing()
{

  return (0) ;
}

/* ********************************************** */
/* acces */
/* ********************************************** */
int acces(int position)
{

  return (0) ;
}


