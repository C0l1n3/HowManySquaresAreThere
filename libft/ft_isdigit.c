/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathe <agathe@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 11:10:43 by cfaure-g          #+#    #+#             */
/*   Updated: 2021/01/25 17:01:03 by agathe           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (48 <= c && c <= 57)
		return (1);
	return (0);
}
/*
**int	main(void)
**{
**int	c = '5';
**if (ft_isdigit(c) == 1)
**printf("%d is a numerical character", c);
**else
**printf("%d is not a numerical character", c);
**}
*/
