#include "substring.h"

/**
 * find_substring - function that finds all the possible substrings
 * containing a list of words, within a given string.
 *
 * @s: string to scan
 * @words: the array of words all substrings
 * @nb_words: number of elements in the array words
 * @n: address at which to store the number of elements in the returned array.
 * Return: allocated array
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int word_len = strlen(words[0]), total_len = nb_words * word_len;
	int s_len = strlen(s), *indices = NULL, i, j, k;
	int seen[nb_words], found;

	*n = 0;

	if (s_len < total_len || nb_words == 0)
		return (NULL);


	for (i = 0; i <= s_len - total_len; i++)
	{
		for (j = 0; i < nb_words; i++)
			seen[j] = 0;

		j = 0;
		while (j < nb_words)
		{
			found = 0;
			for (k = 0; k < nb_words; k++)
			{
				if (!seen[k] && !strncmp(&s[i + k * word_len], words[k], word_len))
				{
					seen[k] = 1;
					found = 1;
					break;
				}
			}
			if (!found)
				break;

			j++;
		}

		if (j == nb_words)
		{
			indices = realloc(indices, (*n + 1) * sizeof(int));
			if (!indices)
				return (NULL);

			indices[*n] = i;
			(*n)++;
		}
	}

	return (indices);
}
