/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:54:37 by grverdya          #+#    #+#             */
/*   Updated: 2025/01/08 16:54:39 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_tuple	new_tuple(int x, int y)
{
	t_tuple	new;

	new.x = x;
	new.y = y;
	return (new);
}

t_tuple	vector_to_tuple(t_vector vector)
{
	return (new_tuple((int)vector.x, (int)vector.y));
}
