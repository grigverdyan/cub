/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_printer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:28:47 by dapetros          #+#    #+#             */
/*   Updated: 2025/01/08 16:28:48 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_env_node(t_node *node)
{
	if (node->value)
	{
		if (node->value[0])
			printf("%s=%s\n", node->key, node->value);
		else
			printf("%s=\n", node->key);
	}
}

void	print_dict(t_dict *list)
{
	for_each(list, &print_env_node);
}
