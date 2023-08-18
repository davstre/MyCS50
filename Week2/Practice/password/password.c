// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool lower = false, upper = false, number = false, symbol = false;

    for (int i = 0; i < strlen(password); i++)
    {
        if (password[i] >= 97 && password[i] <= 122) // lowercase
        {
            lower = true;
        }
        if (password[i] >= 65 && password[i] <= 90) // uppercase
        {
            upper = true;
        }
        if (password[i] >= 48 && password[i] <= 57) // number
        {
            number = true;
        }
        if ((password[i] >= 33 && password[i] <= 47) || // ! to /
            (password[i] >= 58 && password[i] <= 64) || // : to @
            (password[i] >= 91 && password[i] <= 96) || // [ to `
            (password[i] >= 123 && password[i] <= 126)) // { to ~
        {
            symbol = true;
        }
    }
    if (lower == true && upper == true && number == true && symbol == true)
    {
        return true;
    }
    return false;
}
