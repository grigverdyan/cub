/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:53:07 by grverdya          #+#    #+#             */
/*   Updated: 2025/01/08 16:53:08 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static size_t	getwordcount(t_string const s, char c)
{
	size_t	count;
	size_t	i;
	size_t	len;

	i = -1;
	count = 1;
	len = ft_strlen(s);
	while (s[++i] && s[i] == c)
		;
	while (s[--len] && s[len] == c && i < len)
		;
	if (i == ft_strlen(s))
		return (0);
	while (s[i] && i < len)
	{
		if (s[i] == c && s[i - 1] != c)
			count++;
		i++;
	}
	return (count);
}

static char	*fillword(const char *s, size_t startindex, size_t len)
{
	char	*word;
	size_t	i;

	i = -1;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (++i < len)
		word[i] = s[startindex + i];
	word[i] = 0;
	return (word);
}

t_text	ft_split(t_string const s, char c)
{
	size_t	startindex;
	size_t	endindex;
	size_t	index;
	size_t	wordcount;
	char	**result;

	startindex = 0;
	index = -1;
	wordcount = getwordcount(s, c);
	result = malloc(sizeof(char *) * (wordcount + 1));
	if (!s || !result)
		return (NULL);
	while (++index < wordcount)
	{
		while (s[startindex] && s[startindex] == c)
			startindex++;
		endindex = startindex;
		while (s[endindex] && s[endindex] != c)
			endindex++;
		result[index] = fillword(s, startindex, endindex - startindex);
		startindex = endindex;
	}
	result[index] = 0;
	return (result);
}
