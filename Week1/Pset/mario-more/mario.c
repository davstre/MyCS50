#include <cs50.h>
#include <stdio.h>


int main(void)
{
    int n, x;
    do
    {
        n = get_int("Height: ");
        x = n; // Placeholder to manipulate 'n' later on
    }
    while ((n < 1) || (n > 8));

    for (int i = 0; i < x; i++) // Main Loop (For Rows)
    {
        n--; // Manipulate values for First Pyramid

        for (int j = 0; j < x; j++) // First Pyramid
        {
            if (j < n)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }

        printf("  "); // Gap

        for (int j = 0; j < x; j++) // Second Pyramid
        {
            if (j <= i)
            {
                printf("#"); // No need to print spaces, " ", on Second Pyramid
            }
        }
        printf("\n"); // New Line
    }
}
