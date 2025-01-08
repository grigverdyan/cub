/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:54:51 by grverdya          #+#    #+#             */
/*   Updated: 2025/01/08 16:54:53 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector	v_inverse(t_vector vector)
{
	t_vector	new_vector;

	new_vector.x = -vector.y;
	new_vector.y = vector.x;
	return (new_vector);
}

double	v_lenght(t_vector vector)
{
	return (sqrt(vector.x * vector.x + vector.y * vector.y));
}
