/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:52:39 by grverdya          #+#    #+#             */
/*   Updated: 2025/01/08 16:52:41 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned char	basic_atouc(t_string str)
{
	unsigned char	result;
	int				i;

	i = -1;
	result = 0;
	while (str[++i])
		result = result * 10 + str[i] - '0';
	return (result);
}
