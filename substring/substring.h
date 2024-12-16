#ifndef SUBSTRING_H
#define SUBSTRING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *find_substring(char const *s, char const **words, int nb_words, int *n);
int initialize_arrays_for_search(int **word_len, int **seen, int nb_words);
void calculate_word_lengths(char const **words, int nb_words,
							int *word_len, int *total_len);
int check_window_for_word(char const *s, int i, char const *word,
						  int word_len);
int process_substring_window(char const *s, int i, int *word_len, int nb_words,
							 int *seen, char const **words);

#endif /* SUBSTRING_H */
