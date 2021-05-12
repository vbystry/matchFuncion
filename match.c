/*
 * Funkcja ustalająca zgodność napisu z wzorcem. 
 * Znak ’?’ we wzorcu oznacza zgodność z dowolnym innym znakiem. 
 * Znak ’*’ oznacza zgodność z dowolnym, również pustym, ciągiem znaków w łańcuchu. 
 * Znak różny od ’?’ i ’*’ oznacza zgodność tylko z samym sobą
 * 
 * Np match(".txt", s) moze sprawdzać czy plik o nazwie s jest formatu .txt
 */ 

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char star=0x2A;
char Q=0x3F;

bool match(char* wzorzec, char* lancuch)
{
    if(wzorzec[0]=='\0' && lancuch[0]=='\0')
    {
        return true;
    }
    else if(wzorzec[0]==star)
    {
        
        if(wzorzec[1]=='\0')
        {
            return true;
        }
        else if(wzorzec[1]!=lancuch[0] && (lancuch[0]!='\0')) 
        {
            return match(wzorzec, &lancuch[1]);
        }
        else if(wzorzec[1]==lancuch[0])
        {
            
            if(match(&wzorzec[1], &lancuch[0]))
            {
                
                return true;
            }
            else
            {
                return match(wzorzec, &lancuch[1]);
            }
        }
        else
        {
            return false;
        }
    }
    else if(wzorzec[0]==lancuch[0] || ((wzorzec[0]==Q) && (lancuch[0]!='\0')))
    {
        return match(&wzorzec[1], &lancuch[1]);
    }
    else
    {
        return false;
    }
}

int main(void)
{
    char wzor[100];
    char lan[100];
    printf("Podaj wzor: ");
    scanf("%s", wzor);
    printf("Podaj łańcuch do porownania: ");
    scanf("%s", lan);
    printf("przypasowanie: %d\n", match(wzor,lan));
}