#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

char chaineEntree[1000];
int charToNb(char c);
int h;
int i;
int j;
int cpt=0;
char chaineSortie[1000];
char codeToChar(int cpt, char numero);

int main(int argc, char *argv[])
{
    printf("Tapez votre message\n");
    scanf("%s",chaineEntree);
    h=strlen(chaineEntree);
    for(i=0 ; i<h ; i++)
    {
        cpt=1;
        while(chaineEntree[i]==chaineEntree[i+1])
        {
            cpt++;
            i++;
        }
        if(chaineEntree[i]!='#')
        {
            chaineSortie[j]=codeToChar(cpt, chaineEntree[i]);
            j++;
        }
    }
    printf("Voici votre message : %s\n", chaineSortie);
    return 0;
}



int charToNb(char c) // Convertit un caractère en son équivalent numérique ('0' devient 0, '1' devient 1 ... etc...)
{                           //  /!\ un seul chiffre/caractère, pas de nombres autorisées ni de chaînes.
    int retour;cpt++;
            i++;

    retour=c-48;
    return(retour);
}

char codeToChar(int cpt, char numero)
{
    char lettre;
    if(numero=='2')
    {
        switch(cpt)
        {
        case 1 :
            lettre='a';
            break;
        case 2:
            lettre='b';
            break;
        case 3:
            lettre='c';
            break;
        default:
            lettre=' ';
        }
    }
    else
    if(numero=='3')
    {
        switch(cpt)
        {
            case 1 :
            lettre='d';
            break;
        case 2:
            lettre='e';
            break;
        case 3:
            lettre='f';
            break;
        default:
            lettre=' ';
        }
    }
    else
    if(numero=='4')
    {
        switch(cpt)
        {
        case 1 :
            lettre='g';
            break;
        case 2:
            lettre='h';
            break;
        case 3:
            lettre='i';
            break;
        default:
            lettre=' ';
        }
    }
    else
    if(numero=='5')
    {
        switch(cpt)
        {
        case 1 :
            lettre='j';
            break;
        case 2:
            lettre='k';
            break;
        case 3:
            lettre='l';
            break;
        default:
            lettre=' ';
        }
    }
    else
    if(numero=='6')
    {
        switch(cpt)
        {
        case 1 :
            lettre='m';
            break;
        case 2:
            lettre='n';
            break;
        case 3:
            lettre='o';
            break;
        default:
            lettre=' ';
        }
    }
    else
    if(numero=='7')
    {
        switch(cpt)
        {
        case 1 :
            lettre='p';
            break;
        case 2:
            lettre='q';
            break;
        case 3:
            lettre='r';
            break;
        case 4:
            lettre='s';
            break;
        default:
            lettre=' ';
        }
    }
    else
    if(numero=='8')
    {
        switch(cpt)
        {
        case 1 :
            lettre='t';
            break;
        case 2:
            lettre='u';
            break;
        case 3:
            lettre='v';
            break;
        default:
            lettre=' ';
        }
    }
    else
    if(numero=='9')
    {
        switch(cpt)
        {
        case 1 :
            lettre='w';
            break;
        case 2:
            lettre='x';
            break;
        case 3:
            lettre='y';
            break;
        case 4:
            lettre='z';
            break;
        default:
            lettre=' ';
        }
    }
    else
    if(numero=='#')
    {
        lettre=' ';
    }
    return lettre;
}
