// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace (string word);

int main(int argc, string argv[])
{
    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            printf("%s ", replace(argv[i]));
        }
    }
    else
    {
        printf("Error!\nUsage: / $ ./no-vowels \"Enter-Input-Here\"");
    }
    printf("\n");
}

string replace (string x)
{
    for(int i = 0; i < strlen(x); i++)
        switch (x[i])
        {
            case 'a':
                x[i] = '6';
                break;
            case 'e':
                x[i] = '3';
                break;
            case 'i':
                x[i] = '1';
                break;
            case 'o':
                x[i] = '0';
                break;
        }
    return x;
}
