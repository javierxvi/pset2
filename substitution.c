#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    if (argc == 2)
    {
        bool check = true;
        
        if (strlen(argv[1]) != 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        else
        {

            for (int i = 0, n = strlen(argv[1]); i < n; i++)
            {
                if (isalpha(argv[1][i])) //evalúa si la key que se ingresa está compuesta sólo de letras
                { 
                    for (int c = 0; c < n; c++)
                    {
                        for (int j = c + 1; j < n; j++)
                        {
                            if (argv[1][c] == argv[1][j])   //evalúa que no haya caracteres repetidos en la key
                            {
                                check = false;
                            }
                            
                        }
                    }
                    
                    if (check == false)
                    {
                        printf("Key must not contain repeated characters.\n");
                    }
                }
                else
                {
                    printf("Usage: ./substitution key\n");
                    check = false;
                }
            }
        }
        
        if (check == false)
        {
            return 1;
        }
        else
        {
            string ptext = get_string("plaintext: ");
            string ctext = ptext;
            
            printf("ciphertext: ");
            
            string key = argv[1];
            
            for (int i = 0, n = strlen(ctext); i < n; i++)
            {
                if (isalpha(ptext[i]))                      //evalúa si cada caracter está en el alfabeto
                {
                    if (ptext[i] < 91)                      //evalúa en caso de que el caracter sea mayúscula
                    {
                        int cont = ptext[i];                //tengo que hacer que ptext[i] sea reemplazado por key[cont] donde 'cont' es la posición alfabética 
                        ctext[i] = toupper(key[cont - 65]);          //análoga a la posición original de la letra ptext[i]
                        printf("%c", ctext[i]);  
                    }
                    else                                    //evalúa en caso de que el caracter sea minúscula
                    {
                        int cont = ptext[i];                //tengo que hacer que ptext[i] sea reemplazado por key[cont] donde 'cont' es la posición alfabética
                        ctext[i] = tolower(key[cont - 97]); //análoga a la posición original de la letra ptext[i]
                        printf("%c", ctext[i]);
                    }
                }
                else
                {
                    printf("%c", ptext[i]);
                }
            }
            printf("\n");
        }
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}
