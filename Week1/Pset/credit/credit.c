#include <cs50.h>
#include <stdio.h>

long n, plc, div = 100;
int x, y = 0;

int main(void)
{
    n = get_long("Number: "); // Prompt for credit card number
    plc = n;                  // placeholder

    for (int i = 0; i < 16; i++) // loop is 16 regardless of length
    {
        x = n % 10;     // addend to checksum
        if (i % 2 != 0) // even digit conditions (from the right)
        {
            x *= 2;    // product
            if (x > 9) // if double-digit product
            {
                x = (x % 10) + 1; // +1 is always for tens digit since max value of product is 18 (9x2)
            }
        }
        y += x;     // checksum for both even and odd
        n = n / 10; // next digit for loop
    }

    n = plc; // recall n value for next condition process

    if ((y % 10) == 0) // checksum condition if ones digit is zero
    {
        if ((n / 10000000000000 == 34) || (n / 10000000000000 == 37)) // AMEX - 34 or 37 start, 15 digits
        {
            printf("AMEX\n");
        }
        else if ((n / 1000000000000 == 4) || (n / 1000000000000000 == 4)) // VISA - 4 start, 13 or 16 digits
        {
            printf("VISA\n");
        }
        else if ((n >= 5100000000000000) && (n <= 5599999999999999)) // MASTERCARD - 51 to 55 start, 16 digits
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n"); // INVALID for failing any specific card condition
        }
    }
    else
    {
        printf("INVALID\n"); // INVALID for failing checksum
    }
}