/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:11:48 by prichugh          #+#    #+#             */
/*   Updated: 2023/11/23 12:32:25 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = s;
	i = 0;
	while (i != n)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
int main()
{
    char s[] = "hi, welcome to chilli's";
    ft_memset(s, 'a', 6);
    printf("%s\n", s);
    return (0);
}
*/
