#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // TODO
    string msg = get_string("Message: ");
    int n = strlen(msg);

    for (int i = 0; i < n; i++)
    {
        int x = msg[i];
        for (int j = (BITS_IN_BYTE - 1); j >= 0; j--)
        {
            int y = pow(2, j);
            print_bulb(x / y);
            x = x % y;
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
