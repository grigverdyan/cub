/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:28:57 by dapetros          #+#    #+#             */
/*   Updated: 2025/01/08 16:28:58 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_node	*find_node_with_key(t_dict *list, char *key)
{
	t_node	*node;

	if (list->count <= 0)
		return (NULL);
	node = list->head;
	while (node)
	{
		if (!ft_strcmp(key, node->key))
			return (node);
		node = node->next;
	}
	return (NULL);
}

void	for_each(t_dict *list, void (*func)(t_node *))
{
	int		i;
	t_node	*current;

	i = -1;
	current = list->head;
	while (++i < list->count)
	{
		func(current);
		current = current->next;
	}
}

void	unset_index(t_node *node)
{
	node->index = -1;
}
