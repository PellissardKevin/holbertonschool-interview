#include "palindrome.h"

int is_palindrome(unsigned long n)
{
	unsigned long reversed = 0, original = n, remainder;

	if (n < 10)
		return (1);

	while (n != 0)
	{
		remainder = n % 10;
		reversed = reversed * 10 + remainder;
		n /= 10;
	}

	if (original == reversed)
		return (1);
	else
		return (0);
}
