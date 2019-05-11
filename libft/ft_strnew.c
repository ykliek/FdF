/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 12:10:43 by ykliek            #+#    #+#             */
/*   Updated: 2018/10/30 12:10:45 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str1;

	str1 = (char*)malloc((size + 1) * sizeof(char));
	if (str1 == NULL)
		return (NULL);
	ft_memset(str1, (int)'\0', size + 1);
	return (str1);
}
