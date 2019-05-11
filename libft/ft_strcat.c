/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:43:09 by ykliek            #+#    #+#             */
/*   Updated: 2018/10/26 15:43:10 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int	count_1;
	int	count_2;

	count_1 = 0;
	count_2 = 0;
	while (s1[count_1] != '\0')
		count_1++;
	while (s2[count_2] != '\0')
	{
		s1[count_1] = s2[count_2];
		count_1++;
		count_2++;
	}
	s1[count_1] = '\0';
	return (s1);
}
