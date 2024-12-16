#include "substring.h"

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
	int total_len, s_len = strlen(s), *indices = NULL, *word_len, *seen, i;

	*n = 0;
	if (s_len == 0 || nb_words == 0)
		return (NULL);

	if (!initialize_arrays_for_search(&word_len, &seen, nb_words))
		return (NULL);

	calculate_word_lengths(words, nb_words, word_len, &total_len);

	if (s_len < total_len)
	{
		free(word_len);
		free(seen);
		return (NULL);
	}

	for (i = 0; i <= s_len - total_len; i++)
	{
		if (process_substring_window(s, i, word_len, nb_words, seen, words))
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

/**
 * initialize_arrays_for_search - initialise les tableaux de longueur de mots
 * et de suivi des mots trouvés.
 *
 * @word_len: tableau pour stocker la longueur de chaque mot
 * @seen: tableau pour suivre quels mots ont été trouvés
 * @nb_words: nombre de mots
 * Return: 1 en cas de succès, 0 en cas d'échec
 */
int initialize_arrays_for_search(int **word_len, int **seen,
										int nb_words)
{
	*word_len = malloc(nb_words * sizeof(int));
	if (!*word_len)
		return (0);

	*seen = malloc(nb_words * sizeof(int));
	if (!*seen)
	{
		free(*word_len);
		return (0);
	}

	return (1);
}

/**
 * calculate_word_lengths - calcule la longueur de chaque mot et la longueur
 * totale de tous les mots combinés.
 *
 * @words: tableau de mots
 * @nb_words: nombre d'éléments dans le tableau words
 * @word_len: tableau pour stocker la longueur de chaque mot
 * @total_len: longueur totale de tous les mots combinés
 */
void calculate_word_lengths(char const **words, int nb_words,
								   int *word_len, int *total_len)
{
	int i;
	*total_len = 0;
	for (i = 0; i < nb_words; i++)
	{
		word_len[i] = strlen(words[i]);
		*total_len += word_len[i];
	}
}

/**
 * check_window_for_word - vérifie si un mot spécifique correspond
 * à l'indice donné dans la chaîne.
 *
 * @s: chaîne à analyser
 * @i: indice de départ pour la correspondance
 * @word: le mot à vérifier
 * @word_len: longueur du mot
 * Return: 1 si les mots correspondent, 0 sinon
 */
int check_window_for_word(char const *s, int i, char const *word,
								 int word_len)
{
	return (strncmp(&s[i], word, word_len) == 0);
}

/**
 * process_substring_window - vérifie si tous les mots sont présents
 * dans la fenêtre actuelle.
 *
 * @s: chaîne à analyser
 * @i: indice de départ pour la fenêtre
 * @word_len: tableau des longueurs de mots
 * @nb_words: nombre de mots
 * @words: tableau de mots
 * @seen: tableau de suivi des mots trouvés
 * Return: 1 si tous les mots sont trouvés, 0 sinon
 */
int process_substring_window(char const *s, int i, int *word_len,
									int nb_words, int *seen, char const **words)
{
	int j, k, found;

	for (j = 0; j < nb_words; j++)
		seen[j] = 0;

	j = 0;
	found = 1;
	while (j < nb_words && found)
	{
		found = 0;
		for (k = 0; k < nb_words; k++)
		{
			if (!seen[k] &&
				check_window_for_word(
					s, i + j * word_len[k], words[k], word_len[k]))
			{
				seen[k] = 1;
				found = 1;
				j++;
				break;
			}
		}
	}

	return (j == nb_words);
}
