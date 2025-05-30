#include "palindrome.h"

/**
 * is_palindrome - Checks whether or not a given unsigned integer is a
 * palindrome.
 *
 * @n: the number to be checked.
 * 
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome.
 */
int is_palindrome(unsigned long n)
{
    unsigned long digits[20];
    int i = 0;

    while (n != 0)
    {
        digits[i++] = n % 10;
        n /= 10;
    }

    int start = 0;
    int end = i - 1;

    while (start < end)
    {
        if (digits[start] != digits[end])
            return 0;
        start++;
        end--;
    }

    return 1;
}
