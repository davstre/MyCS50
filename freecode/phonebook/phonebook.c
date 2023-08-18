#include <stdio.h>
#include <cs50.h>

int main (void)
{
    string Name = get_string("Name: " );
    int Age = get_int("Age: " );
    long Phone = get_long("Phone Number: ");

    printf("Your name is %s. Your age is %i. Your Phone Number is %li.\n", Name, Age, Phone);
}