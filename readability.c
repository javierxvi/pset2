#include <cs50.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

//makes Coleman-Liau index text
void readability(double s, double w, double l); 

int main(void) 
{
    double s = 0, w = 1, l = 0;
    
    string text = get_string("Text: ");
    
    //checks number of sentences, words and letters
    for (int i = 0; i < strlen(text); i++) 
    {
        
        switch (text[i])
        {
            
            case 46: s++; //"."
                break;
            case 33: s++; //"!"
                break;
            case 63: s++; //"?"
                break;
            case 32: w++; //" "
                break;
            case 39:      //" ' "
            case 34:      //' " '
            case 44:      //" , "
            case 58:      //" : "
            case 59:      //" ; "
                break;
            default:
                if (text[i] > 90 && text[i] < 65)
                { }
                else
                {
                    l++;
                }
                break;
        }
    }

    readability(s, w, l);
}

void readability(double s, double w, double l)
{
    l = l * 100 / w;
    s = s * 100 / w;

    int index = round(0.0588 * l - 0.296 * s - 15.8);
    
    if ( index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
