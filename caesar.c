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
        int number;

        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (argv[1][i] >= '0' && argv[1][i] <= '9') //evalúa si la key que se ingresa está compuesta sólo de números
            { }
            else
            {
                check = false;
                return 1;
            }
        }

        if (check == false)
        {
            printf("Usage: ./caesar\n");
        }
        else
        {
            string palabra = get_string("plaintext: ");
            
            printf("ciphertext: ");

            int parseKey = (int)strtol(argv[1], NULL, 10); //la key ingresada pasada a INT
            
            int c = parseKey % 26; //cuando la key es mayor a 26


            for (int i = 0, n = strlen(palabra); i < n; i++)
            {
                if (isalpha(palabra[i])) //evalúa si cada caracter está en el alfabeto
                {
                    if (isupper(palabra[i]))
                    {
                        
                        if (((palabra[i] + c) > 90)) //evalúa en caso de que supere la Z en ASCII
                        {
                            printf("%c", (((palabra[i]) + c) - 26));
                            //printf("%c", (((palabra[i]) + parseKey) % 91) + 65);
                        }
                        else
                        {
                            printf("%c", (palabra[i]) + c);
                            //printf("%c", ((palabra[i]) + parseKey));
                        }
                    }
                    else
                    {
                        if (((palabra[i] + c) > 122)) //evalúa en caso de que supere la z en ASCII
                        {
                            printf("%c", (((palabra[i]) + c) - 26));
                            //printf("%c", (((palabra[i] + parseKey)) % 123) + 97);
                        }
                        else
                        {
                            printf("%c", (palabra[i]) + c);
                            //printf("%c", ((palabra[i] + parseKey) % 123));
                        }
                    }
                }
                else //para el resto de los símbolos
                {
                    printf("%c", palabra[i]);
                }
            }

            printf("\n");
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}
