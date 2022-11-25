/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 11:14:00 by cfaure-g          #+#    #+#             */
/*   Updated: 2021/01/28 15:34:59 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		i;

	i = 0;
	while (s1 && s1[i])
		i++;
	if (!(dest = (char *)wrmalloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
**int	main(void)
**{
**	char	*str = "Hello world";
**
**	printf("%s", ft_strdup(str));
**	return (0);
**}
*/
