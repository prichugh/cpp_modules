/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:50:26 by prichugh          #+#    #+#             */
/*   Updated: 2023/11/23 12:50:26 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
		n--;
	}
	return (s1[i] - s2[i]);
}
/*
int main(void)
{
	char s1[] = "Happy birthday to you";
	char s2[] = "Happy birthday to you, Happy birthday dear 42";
	int n = 22;

	int result = ft_strncmp(s1, s2, n);
	int real = strncmp(s1, s2, n);
	printf("\nMy Result: %i\n", result);
	printf("\nReal Result: %i\n\n", real);
	return (0);
}
*/
