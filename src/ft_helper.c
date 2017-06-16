/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 17:31:46 by kzeng             #+#    #+#             */
/*   Updated: 2017/03/23 17:31:48 by kzeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_nwords(char *s, char c, int i)
{
	int		nwords;
	int		begin;
	int		len;

	nwords = 0;
	begin = 0;
	len = ft_strlen(s);
	while (s[i] != '\0')
	{
		if (begin == 0 && s[i] != c)
		{
			begin = 1;
			nwords++;
		}
		if (i <= len - 1)
		{
			if (begin == 1 && s[i + 1] == c)
				begin = 0;
		}
		i++;
	}
	return (nwords);
}

static char	*ft_word(char *s, int startindex, int endindex)
{
	char	*word;
	int		k;

	word = (char *)malloc(sizeof(char) * (endindex - startindex + 1));
	if (word == NULL)
		return (NULL);
	k = 0;
	while (startindex < endindex)
	{
		word[k] = s[startindex];
		k++;
		startindex++;
	}
	word[k] = '\0';
	return (word);
}

char		**ft_strsplit(char *s, char c)
{
	char	**fresh;
	int		i;
	int		startindex;
	int		endindex;
	int		nwords;

	i = 0;
	startindex = 0;
	endindex = 0;
	nwords = ft_nwords(s, c, i);
	if ((fresh = (char **)malloc(sizeof(char *) * (nwords + 1))) == NULL)
		return (NULL);
	while (i < nwords)
	{
		startindex = endindex;
		while (s[startindex] == c)
			startindex++;
		endindex = startindex;
		while (s[endindex] != c && s[endindex] != '\0')
			endindex++;
		if ((fresh[i++] = ft_word(s, startindex, endindex)) == NULL)
			return (NULL);
	}
	fresh[i] = 0;
	return (fresh);
}
