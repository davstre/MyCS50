#include <cs50.h>
#include <stdio.h>

long n, plc, div = 100;
int x, y = 0;

int main(void)
{
    n = get_long("Number: "); // Prompt for credit card number
    plc = n; //placeholder

    printf("%ld\n", n);
    for (int i = 0; i < 16; i++)
    {
        x = n % 10;
        if (i % 2 != 0){
            x *= 2;
            if (x > 9)
            {
                x = (x % 10) + 1;
            }

        }
        y += x;
        printf("%i  %ld %i\n", x, n, y);
        n = n / 10;
    }

    n = plc;

    if ((y % 10) == 0)
    {
        if((n / 10000000000000 == 34) || (n / 10000000000000 == 37))
        {
            printf("AMEX %i\n", y);
        }
        else if((n / 1000000000000 == 4) || (n / 1000000000000000 == 4))
        {
            printf("VISA %i\n", y);
        }
        else if((n >= 51000000000000) && (n <= 5599999999999999))
        {
            printf("MASTERCARD %i\n", y);
        }
        else
        {
            printf("INVALID %i\n", y);
        }
    }
    else
    {
        printf("INVALID %i\n", y);
    }
}