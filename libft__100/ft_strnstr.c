/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:48:26 by prichugh          #+#    #+#             */
/*   Updated: 2023/11/23 12:48:26 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	n;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (i < len && big[i])
	{
		n = 0;
		while (big[i + n] == little[n] && little[n] && (i + n) < len)
		{
			n++;
			if (little[n] == '\0')
				return ((char *) big + i);
		}
		i++;
	}
	return (NULL);
}
/*
int main(void)
{
	char big[] = "Finding a needle in a haystack";
	char little[] = "needle";

	char *ft_result = ft_strnstr(big, little, 17);
	printf("\nBig: %s\n", big);
	printf("\nLittle: %s\n", little);
	printf("\nFirst occurance of little in big: %s\n\n", (char *)ft_result);
	return (0);
}
*/
