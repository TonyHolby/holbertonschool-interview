#include "substring.h"

/**
 * is_valid - Checks if a substring starting at a given index is a valid.
 *
 * @s: the string to scan.
 * @words: the array of words all substrings must be a concatenation of.
 * @nb_words: the number of elements in the array words.
 * @start: the starting index in s to check.
 *
 * Return: 0 or 1.
 */
static int is_valid(const char *s, const char **words, int nb_words, int start)
{
	int wlen = strlen(words[0]);
	int used[nb_words];

	for (int i = 0; i < nb_words; i++)
		used[i] = 0;

	for (int i = 0; i < nb_words; i++)
	{
		const char *block = s + start + i * wlen;
		int found = 0;

		for (int j = 0; j < nb_words; j++)
		{
			if (!used[j] && strncmp(block, words[j], wlen) == 0)
			{
				used[j] = 1;
				found = 1;
				break;
			}
		}
		if (!found)
			return (0);
	}
	return (1);
}

/**
 * *find_substring - finds all the possible substrings containing a list of
 * words, within a given string.
 *
 * @s: the string to scan.
 * @words: the array of words all substrings must be a concatenation of.
 * @nb_words: the number of elements in the array words.
 * @n: holds the address at which to store the number of elements in the
 * returned array.
 *
 * Return: an allocated array, storing each index in s, at which a substring
 * was found. If no solution is found, NULL can be returned.
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int slen = strlen(s);
	int wlen = strlen(words[0]);
	int total = wlen * nb_words;
	int *allocated_array = malloc(sizeof(int) * 1000);

	if (!allocated_array)
		return (NULL);

	*n = 0;

	for (int i = 0; i <= slen - total; i++)
	{
		if (is_valid(s, words, nb_words, i))
		{
			allocated_array[*n] = i;
			(*n)++;
		}
	}

	if (*n == 0)
	{
		free(allocated_array);
		return (NULL);
	}

	return (allocated_array);
}
