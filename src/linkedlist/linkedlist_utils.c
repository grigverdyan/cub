/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:29:32 by dapetros          #+#    #+#             */
/*   Updated: 2025/01/08 16:29:34 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_lnode(t_lnode *node)
{
	printf("%s", node->value);
}

static void	for_each_list(t_list *list, void (*func)(t_lnode *))
{
	t_lnode	*current;

	if (list->count == 0)
		return ;
	current = list->head;
	while (current)
	{
		func(current);
		current = current->next;
	}
}

void	print_list(t_list *list)
{
	for_each_list(list, print_lnode);
}

void	free_list(t_list *list)
{
	while (list->count > 0)
		remove_node(list);
	free(list);
}

void	free_list_nodes(t_list *list)
{
	while (list->count > 0)
		remove_node(list);
}
