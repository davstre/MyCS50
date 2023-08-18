#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

bool only_digits(string check);
char rotate(char c, int key);

int x;

int main(int argc, string argv[])
{
    if (argc == 2 && only_digits(argv[1])) // must have 1 argument or input; must have only numerical input
    {
        string text = get_string("plaintext:  ");
        for (int i = 0; i < strlen(text); i++)
        {
            text[i] = rotate(text[i], x); //iterative cyphering of characters
        }
        printf("ciphertext: %s\n", text);
        return 0;
    }
    else
    {
        printf("Error-Proper Usage:\n\"$ ./caesar 'numeric key'\"\n");
        return 1;
    }
}

bool only_digits(string check)
{
    int y = 0;
    for (int i = strlen(check); i > 0; i--)
    {
        if (isdigit(check[y]))
        {
            x += (check[y] - 48) * pow(10, (i-1)); // convert numeric ASCII to int; multiply to base10 of curent position
            y++;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

char rotate(char c, int key)
{
    if (isupper(c))
    {
        c = (c - 64 + key) % 26; // c - 64 is ASCII conversion for uppercase to pass through formula
        c = c + 64; //bring back ASCII equivalent
    }
    if (islower(c))
    {
        c = (c - 96 + key) % 26; // same concept with lowercase
        c = c + 96;
    }
    return c;
}