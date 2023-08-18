#include <cs50.h>
#include <stdio.h>

int llama, end, n;

int main(void)
{
    do // TODO: Prompt for start size
    {
        printf("Start Size: ");
        scanf("%i", &llama);
    }
    while (llama < 9);

    do // TODO: Prompt for end size
    {
        printf("End Size: ");
        scanf("%i", &end);
    }
    while (end < llama);


    while (llama < end) // TODO: Calculate number of years until we reach threshold
    {
        llama = llama + (llama / 3) - (llama / 4);
        n++;
    }

    printf("Years: %i\n", n); // TODO: Print number of years
}
