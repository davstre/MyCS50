#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string in = get_string("Text: ");
    float L = 100 * count_letters(in) / count_words(in);
    float S = 100 * count_sentences(in) / count_words(in);

    float index = 0.0588 * L - 0.296 * S - 15.8;
    printf("Letters: %i\n", count_letters(in));
    printf("Words: %i\n", count_words(in));
    printf("Sentences: %i\n", count_sentences(in));
    printf("Grade %i\n", (int) index);
}

int count_letters(string text)
{
    int x = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            x++;
        }
    }
    return x;
}

int count_words(string text)
{
    int x = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isspace(text[i]))
        {
            x++;
        }
    }
    return x + 1;
}

int count_sentences(string text)
{
    int x = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            x++;
        }
    }
    return x;
}