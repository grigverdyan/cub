/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:53:51 by grverdya          #+#    #+#             */
/*   Updated: 2025/01/08 16:53:52 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_sprite_info	new_sprite_info(int x, int y, int texture)
{
	t_sprite_info	sprite;

	sprite.pos = new_vector(y + 0.5, x + 0.5);
	sprite.texture = texture;
	return (sprite);
}

t_animated_sprite	get_animated_sprite(t_data *data, int letter)
{
	t_animated_sprite	current_sprite;

	current_sprite = (t_animated_sprite){0};
	if (letter == ENEMY)
		current_sprite = data->a_sprites[ENEMY_INDEX];
	return (current_sprite);
}

unsigned int	get_animated_sprite_color(char letter,
	t_data *data, int x, int y)
{
	unsigned int		color;
	t_animated_sprite	current_sprite;

	current_sprite = get_animated_sprite(data, letter);
	color = get_img_color(current_sprite.sprites
		[current_sprite.current_index], x, y);
	return (color);
}
