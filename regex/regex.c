#include <stdio.h>

/**
 * first_match - Check if first char of str matches first char of pattern.
 *
 * @str: the string to scan.
 * @pattern: the regular expression.
 *
 * Return: 1 if first char matches, else 0.
 */
int first_match(const char *str, const char *pattern)
{
	return (*str != '\0' && (*pattern == *str || *pattern == '.'));
}

/**
 * regex_match - Checks whether a given pattern matches a given string.
 *
 * @str: the string to scan.
 * @pattern: the regular expression.
 *
 * Return: 1 if the pattern matches the string, or 0 if it doesn’t.
 */
int regex_match(const char *str, const char *pattern)
{
	if (*pattern == '\0')
		return (*str == '\0');

	if (*(pattern + 1) == '*')
	{
		if (regex_match(str, pattern + 2))
			return (1);

		if (first_match(str, pattern) && regex_match(str + 1, pattern))
			return (1);

		return (0);
	}

	if (first_match(str, pattern))
		return (regex_match(str + 1, pattern + 1));

	return (0);
}
