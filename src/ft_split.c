/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:58:56 by ccottin           #+#    #+#             */
/*   Updated: 2021/05/31 15:44:42 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static char	**if_ndest(char **ret, int y)
{
	y -= 1;
	while (0 <= y)
	{
		free(ret[y]);
		y--;
	}
	free(ret);
	return (NULL);
}

static char	*put_str(char *s, char c, size_t i)
{
	size_t	y;
	size_t	j;
	char	*dest;

	y = 0;
	j = i;
	while (s[j] != c && s[j])
	{
		j++;
		y++;
	}
	dest = ft_calloc(sizeof(char) * (y + 1));
	if (!dest)
		return (NULL);
	y = 0;
	j = i;
	while (s[i] != c && s[j++])
	{
		dest[y] = s[i];
		y++;
		i++;
	}
	return (dest);
}

static int	count_c(char *s, char c)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (s[i] && s[i] == c)
		i++;
	if (i == ft_strlen(s))
		return (0);
	while (i < ft_strlen(s))
	{
		while (s[i + 1] == c)
			i++;
		if (s[i] == c)
			y++;
		i++;
	}
	if (s[i - 1] == c)
		y = y - 1;
	return (y + 1);
}

char	**ft_split(char *s, char c)
{
	size_t	i;
	int		x;
	int		y;
	char	**ret;

	if (s == NULL)
		return (0);
	x = count_c(s, c);
	ret = ft_calloc(sizeof(char *) * (x + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	y = -1;
	while (++y < x && ret)
	{
		ret[y] = put_str(s, c, i);
		if (!ret[y])
			ret = if_ndest(ret, y);
		while ((s[i] != c || s[i + 1] == c) && y + 1 < x && ret)
			i++;
		i++;
	}
	return (ret);
}
