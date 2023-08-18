#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int sub[26];

bool verify(string check);
char rotate(char c);

int main(int argc, string argv[])
{
    if (argc == 2 && verify(argv[1])) // must have 1 argument; 26 char; only alphabetical input; non-repeating
    {
        string text = get_string("plaintext:  ");
        for (int i = 0; i < strlen(text); i++)
        {
            text[i] = rotate(text[i]); // iterative cyphering of characters
        }
        printf("ciphertext: %s\n", text);
        return 0;
    }
    else
    {
        printf("Error-Proper Usage:\n\"$ ./caesar '26-alphabetical key'\"\n");
        return 1;
    }
}

bool verify(string check)
{
    if (strlen(check) != 26)
    {
        return 0;
    }
    for (int i = 0; i < 26; i++)
    {
        if (isalpha(check[i]))
        {
            for (int j = i + 1; j < 26; j++)
            {
                if (check[i] == check[j])
                {
                    return 0;
                }
            }
            sub[i] = toupper(check[i]);
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

char rotate(char c)
{
    int x = toupper(c) - 65;
    if (isupper(c))
    {
        c = sub[x];
    }
    else if (islower(c))
    {
        c = tolower(sub[x]);
    }
    return c;
}