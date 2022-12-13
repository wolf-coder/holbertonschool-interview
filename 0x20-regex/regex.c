#include "regex.h"

/**
*regex_match - compares 2 strings including the presence of * special character
*@str: first string
*@pattern: second string
*Return: 1 if same, 0 if not
*/
int regex_match(char const *str, char const *pattern)
{
    /* null char */
	if (*str == '\0' && *pattern == '\0')
		return (1);

	/*  skip to next char (aestrik)*/
	if ((*str == '\0') && (*pattern == '*'))
		return (regex_match(str, pattern + 1));

	/* check the next char */
	if (*str == *pattern)
		return (regex_match(str + 1, pattern + 1));


	if (*pattern == '.')
		return (regex_match(str + 1, pattern + 1));
	if (*pattern == '*')
		return ((regex_match(str, pattern + 1)) || (regex_match(str + 1, pattern)));
	if (*str != *pattern)
		if ((*str != '\0') && (*pattern != '\0'))
			if ((*pattern != '*') && (*pattern != '.'))
				return (regex_match(str, pattern + 1));
	return (0);
}
