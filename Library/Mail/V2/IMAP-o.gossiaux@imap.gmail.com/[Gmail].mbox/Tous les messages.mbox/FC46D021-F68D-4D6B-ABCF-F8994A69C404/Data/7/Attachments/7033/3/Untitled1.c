#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int convertCharToNb(char c);
int somme1[10];
int somme2[10];
char tab[100];

int main(int argc, char *argv[])
{
  char chaine[100];
  printf("Veuillez saisir le code ISBN\n");
  scanf("%s", chaine);
  printf("Vous avez saisi le code ISBN %s\n",chaine);
  int j=0;
  int i=0;
  int h;
  h=strlen(chaine);
  for(i=0; i<h; i++)
  {
      if(chaine[j]=='X')
      {
        tab[i]=10;
      }
        else
        if(chaine[j]=='-')
        {
            j++;
        }
        else
        {
            tab[i]=convertCharToNb(chaine[j]);
        }
      j++;
  }
  somme1[0]=tab[0];
  for(i=1;i<10;i++)
    {
        somme1[i]=somme1[i-1]+tab[i];
    }
   somme2[0]=somme1[0];
   for(i=1;i<10;i++)
    {
        somme2[i]=somme2[i-1]+somme1[i];
    }
   printf("%d %d %d %d %d %d %d %d %d %d\n",somme1[0],somme1[1],somme1[2],somme1[3],somme1[4],
          somme1[5],somme1[6],somme1[7],somme1[8],somme1[9]);
   printf("%d %d %d %d %d %d %d %d %d %d\n",somme2[1],somme2[2],somme2[3],somme2[4],
          somme2[5],somme2[6],somme2[7],somme2[8],somme2[9]);
   printf("%d / 11 = %d + %d\n",somme2[9],somme2[9]/11,somme2[9]%11);
   if(somme2[9]%11==0)
    printf("Le code ISBN est correct");
    else
    printf("Le code ISBN est erron�");
    system("PAUSE");
   return 0;
}



int convertCharToNb(char c) // Convertit un caract�re en son �quivalent num�rique ('0' devient 0, '1' devient 1 ... etc...)
{                           //  /!\ un seul chiffre/caract�re, pas de nombres autoris�es ni de cha�nes.
    int retour;
    retour=c-48;
    return(retour);
}
