#include "holberton.h"

/**
 * error_exit - Prints Error, followed by a new line,
 * and exit with a status of 98.
 */
void error_exit(void)
{
	char *error_msg = "Error\n";

	for (int i = 0; error_msg[i]; i++)
		_putchar(error_msg[i]);

	exit(98);
}

/**
 * is_digit - Checks if a string contains only digit characters.
 * @string: Pointer to the string to be validated.
 *
 * Return: 1 if the string contains only digits (0-9), 0 otherwise.
 */
int is_digit(char *string)
{
	for (int i = 0; string[i]; i++)
	{
		if (!isdigit((unsigned char)string[i]))
			return (0);
	}

	return (1);
}

/**
 * print_number - Prints a number stored in an integer array.
 * @num: Pointer to the integer array containing digits.
 * @len: Length of the array.
 */
void print_number(int *num, int len)
{
	int i = 0;

	while (i < len && num[i] == 0)
		i++;

	if (i == len)
	{
		_putchar('0');
	}
	else
	{
		for (; i < len; i++)
			_putchar(num[i] + '0');
	}

	_putchar('\n');
}

/**
 * main - Multiplies two positive numbers.
 * @argc: Argument count.
 * @argv: Argument vector.
 *
 * Return: 0 on success, 98 on error.
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
		error_exit();

	char *num1 = argv[1];
	char *num2 = argv[2];

	if (!is_digit(num1) || !is_digit(num2))
		error_exit();

	int len1 = strlen(num1);
	int len2 = strlen(num2);
	int len_result = len1 + len2;

	int *result = malloc(len_result * sizeof(int));

	if (!result)
		exit(98);

	for (int i = 0; i < len_result; i++)
		result[i] = 0;

	for (int i = len1 - 1; i >= 0; i--)
	{
		for (int j = len2 - 1; j >= 0; j--)
		{
			int mul = (num1[i] - '0') * (num2[j] - '0');
			int sum = mul + result[i + j + 1];

			result[i + j + 1] = sum % 10;
			result[i + j] += sum / 10;
		}
	}

	print_number(result, len_result);
	free(result);

	return (0);
}
