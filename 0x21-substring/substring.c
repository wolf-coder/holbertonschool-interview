#include "substring.h"

/**
 * find_substring - finds all the possible substrings
 * containing a list of words,within a given string.
 * @s: string to scan
 * @words: array of words all substrings must be a concatenation
 ** arrangement of.
 * @nb_words: number of elements in the array words
 * @n: holds the address at which to store the number of elements in the
 **  returned array.
 * Return: allocated array,
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{

	int s_len, Word_Len;
	int check_strs, current_idx, count;
	int *match, *idx_array;
	int i, j, k; /*counters variables*/

	if (!s || !words || !n || nb_words == 0)
		return (NULL);
	s_len = strlen(s);
	Word_Len = strlen(words[0]);
	idx_array = malloc(sizeof(int) * s_len);
	if (!idx_array)
		return (NULL);
	match = malloc(sizeof(int) * nb_words);
	if (!match)
		return (NULL);
	for (i = count = 0; i <= s_len - nb_words * Word_Len; i++)
	{
		memset(match, 0, sizeof(int) * nb_words);
		for (j = 0; j < nb_words; j++)
		{
			for (k = 0; k < nb_words; k++)
			{
				current_idx = i + j * Word_Len;
				check_strs = strncmp(s + current_idx, *(words + k), Word_Len);
				if (!*(match + k) && !check_strs)
				{
					*(match + k) = 1;
					break;
				}
			}
			if (k == nb_words)
				break;
		}
		if (j == nb_words)
			*(idx_array + count) = i, count += 1;
	}
	free(match);
	*n = count;
	return (idx_array);
}
