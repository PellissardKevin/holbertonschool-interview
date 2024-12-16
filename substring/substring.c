#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * find_substring - function that finds all the possible substrings
 * containing a list of words, within a given string.
 *
 * @s: string to scan
 * @words: the array of words to find as substrings
 * @nb_words: number of elements in the array words
 * @n: address at which to store the number of elements in the returned array.
 * Return: allocated array with the indices where substrings start
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int total_len = 0, s_len = strlen(s), *indices = NULL, *word_len;
	int *seen, i, j, k, found;

	*n = 0;

	if (s_len == 0 || nb_words == 0)
	{
		return (NULL);
	}

	word_len = malloc(nb_words * sizeof(int));
	if (!word_len)
		return (NULL);

	for (i = 0; i < nb_words; i++)
	{
		word_len[i] = strlen(words[i]);
		total_len += word_len[i];
	}

	if (s_len < total_len)
	{
		free(word_len);
		return (NULL);
	}

	seen = malloc(nb_words * sizeof(int));
	if (!seen)
	{
		free(word_len);
		return (NULL);
	}

	for (i = 0; i <= s_len - total_len; i++)
	{
		for (j = 0; j < nb_words; j++)
			seen[j] = 0;

		j = 0;
		found = 1;

		while (j < nb_words && found)
		{
			found = 0;
			for (k = 0; k < nb_words; k++)
			{
				if (!seen[k] && strncmp(&s[i + j * word_len[k]], words[k], word_len[k]) == 0)
				{
					seen[k] = 1;
					found = 1;
					j++;
					break;
				}
			}
		}

		if (j == nb_words)
		{
			indices = realloc(indices, (*n + 1) * sizeof(int));
			if (!indices)
			{
				free(word_len);
				free(seen);
				return (NULL);
			}
			indices[*n] = i;
			(*n)++;
		}
	}

	free(word_len);
	free(seen);
	return (indices);
}
