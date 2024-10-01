#include <stdio.h>
#include <stdlib.h>


int is_digit(char *str);
void print_error_and_exit(void);
void multiply(char *num1, char *num2);
void print_number(char *num);

/**
 * is_digit - check if the str is an number
 *
 * @str: string to check
 * Return: 1 if is digit, 0 if not
 */
int is_digit(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/**
 * print_error_and_exit - print error and exit with status 98
 * @void: nothing
 */
void print_error_and_exit(void)
{
	char *error = "Error\n";

	while (*error)
		putchar(*error++);
	exit(98);
}

/**
 * multiply - function to multiply two numbers
 *
 * @num1: first number
 * @num2: second number
 */
void multiply(char *num1, char *num2)
{
	int len1 = 0, len2 = 0, i, j, mul, sum;
	int *result;

	while (num1[len1])
		len1++;
	while (num2[len2])
		len2++;

	result = calloc(len1 + len2, sizeof(int));
	if (result == NULL)
		print_error_and_exit();

	for (i = len1 - 1; i >= 0; i--)
	{
		for (j = len2 - 1; j >= 0; j--)
		{
			mul = (num1[i] - '0') * (num2[j] - '0');
			sum = result[i + j + 1] + mul;

			result[i + j + 1] = sum % 10;
			result[i + j] += sum / 10;
		}
	}

	i = 0;
	while (i < len1 + len2 && result[i] == 0)
		i++;

	if (i == len1 + len2)
		putchar('0');
	else
	{
		for (; i < len1 + len2; i++)
			putchar(result[i] + '0');
	}
	putchar('\n');
	free(result);
}

/**
 * main - main function
 *
 * @argc: number of the argument
 * @argv: list of the argument
 * Return: 0 with success
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
		print_error_and_exit();

	if (!is_digit(argv[1]) || !is_digit(argv[2]))
		print_error_and_exit();

	multiply(argv[1], argv[2]);

	return (0);
}
