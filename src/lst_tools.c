/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 11:57:12 by ykliek            #+#    #+#             */
/*   Updated: 2019/05/12 11:57:14 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		deleteList(t_map	**head)
{
	t_map	*prev;

	while ((*head)->next)
	{
		prev = (*head);
		(*head) = (*head)->next;
		free(prev);
	}
	free(*head);
}

t_map	*getLast(t_map	*head)
{
	t_map		*begin;

	begin = head;
	if (begin)
	{
		while (begin->next)
			begin = begin->next;
	}
	return (begin);
}

void	pushBack(t_map	*head,	t_value	data)
{
	t_map	*tmp;
	t_map	*lst;

	lst = getLast(head);
	tmp = (t_map*)malloc(sizeof(t_map));
	tmp->content = data;
	tmp->next = NULL;
	lst->next = tmp;
}

void	lst_add(t_map	**head,	t_map	*add)
{
	if (*(head))
	{	
		while (add->next)
		{
			pushBack((*head), (*add).content);
			add = add->next;
		}
		pushBack((*head), (*add).content);
	}
	else
	{
		while (add->next)
		{
			push(&(*head), (*add).content);
			add = add->next;
		}
		push(&(*head), (*add).content);
	}	
}

void	push(t_map	**head, t_value	data)
{
	t_map	*tmp;

	tmp = (t_map*)malloc(sizeof(t_map));
	tmp->content = data;
	tmp->next = (*head);
	(*head) = tmp;
}
