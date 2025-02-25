/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:36:48 by prichugh          #+#    #+#             */
/*   Updated: 2024/02/07 14:51:41 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	size_t				i;
	unsigned char		*p;

	p = s;
	i = 0;
	while (i != n)
	{
		p[i] = 0;
		i++;
	}
	return (s);
}
/*
int main()
{
    char s[] = "hello";
    ft_bzero(s, 1);
    printf("%s\n", s);
    return (0);
}
*/
