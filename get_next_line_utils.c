/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 00:51:23 by ykamboua          #+#    #+#             */
/*   Updated: 2024/03/31 06:13:10 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	size;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	if (!size)
		return (ft_free(&s1), NULL);
	str = (char *)(malloc(size + 1));
	if (!str)
		return (NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		str[i++] = s2[j++];
	return (str[i] = '\0', ft_free(&s1), str);
}

char	*ft_strchr(char *str, char c)
{
	if (!str)
		return (NULL);
	else
	{
		while (*str)
		{
			if (*str == c)
				return (str);
			str++;
		}
	}
	return (NULL);
}

char	*ft_strdup(char *str)
{
	char	*s;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(str);
	if (!len || !str)
		return (NULL);
	s = (char *)malloc(len + 1);
	if (!s)
		return (NULL);
	while (str[i])
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

void	ft_free(char **str)
{
	free(*str);
	*str = NULL;
}
