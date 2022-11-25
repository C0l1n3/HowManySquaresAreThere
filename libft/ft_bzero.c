/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 11:01:20 by cfaure-g          #+#    #+#             */
/*   Updated: 2021/01/28 15:40:52 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	if (n && s)
		s = (char*)ft_memset(s, 0, n);
}
/*
**int	main(void)
**{
**char	*s1 = "eeeee";
**char	*s2 = "eeeee";
**
**void	*str1 = &s1;
**void	*str2 = &s2;
**ft_bzero(str1, 5);
**bzero(str2, 5);
**printf("%s\n", str1);
**printf("%s", str2);
**wrfree(str1);
**wrfree(str2);
**wrfree(s1);
**wrfree(s2);
**}
*/
