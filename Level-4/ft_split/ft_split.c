#include <stdio.h>
#include <stdlib.h>

int is_white_space(char c)
{
	if (c == '\t' || c == ' ' || c == '\n' || c == '\v' || c == '\0')
		return 1;
	return 0;
}

int count_words(const char *str)
{
	int count = 0;
	int wflag = 1;
	while (*str)
	{
		while (is_white_space(*str))
		{
			str++;
			wflag = 1;
		}
		if (*str && wflag)
		{
			count++;
			wflag = 0;
		}
		str++;
	}
	return count;
}

int word_len(char *str)
{
	int len = 0;
	while (*str && is_white_space(*str))
		str++;
	while (*str && !is_white_space(*str))
	{
		str++;
		len++;
	}
	return len;
}

char * copyword(char **str)
{
	int len = word_len(*str);
	char *copy = (char*)malloc(sizeof(char) * len + 1);
	if (!copy)
		return NULL;

	int i = 0;
	while (**str && !is_white_space(**str))
	{
		copy[i] = **str;
		(*str)++;
		i++;
	}
	copy[i] = 0;
	return copy;
}

char    **ft_split(char *str)
{
	if (!str)
		return NULL;
	int alen = count_words(str);
	char** split = (char**)malloc(sizeof(char*) * alen + 1);
	if (!split)
		return NULL;

	int i = 0;
	int j = 0;
	while (*str && i < alen)
	{
		while (is_white_space(*str))
			str++;
		while (!is_white_space(*str))
			split[i] = copyword(&str);
			if (!split[i])
			{
				while (i > 0)
					free(split[--i]);
				free(split);
			}
		i++;
	}
	split[alen] = NULL;
	return split;
}
