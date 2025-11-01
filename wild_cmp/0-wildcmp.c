#include "holberton.h"

/**
 * wildcmp - A function that compares two strings and returns 1 if the strings
 *           can be considered identical, otherwise return 0.
 * @s1: A string to compare with s2.
 * @s2: A string that contains the special character *.
 * Return: 1 if the strings can be considered identical, otherwise return 0.
 */
int wildcmp(char *s1, char *s2)
{
	if (*s2 == '\0' && *s1 == '\0')
		return (1);

	if (*s2 == '*')
	{
		if (*(s2 + 1) == '\0')
			return (1);
		if (wildcmp(s1, s2 + 1))
			return (1);
		if (*s1 != '\0' && wildcmp(s1 + 1, s2))
			return (1);
		return (0);
	}

	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	return (0);
}
