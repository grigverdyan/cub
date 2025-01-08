/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:48:30 by grverdya          #+#    #+#             */
/*   Updated: 2025/01/08 16:48:31 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_ceiling(t_data *data, t_draw draw, int col)
{
	int	row;

	row = -1;
	while (++row < draw.ceiling_size)
		*(unsigned int *)(data->frame.data_addr
				+ (row * data->frame.size_line + col
					* (data->frame.bits_per_pixel / 8)))
			= get_color(*(data->ceiling_color));
}

static unsigned int	get_texture_color(t_data *data, t_draw *draw)
{
	int	tex_y;
	int	color;

	color = 0;
	draw->tex_pos += draw->ratio;
	tex_y = (int)draw->tex_pos & (64 - 1);
	if (draw->side == 0 && draw->ray.x > 0)
		color = data->textures->south.texture[tex_y + 64 * draw->tex_x];
	else if (draw->side == 0 && draw->ray.x < 0)
		color = data->textures->north.texture[tex_y + 64 * draw->tex_x];
	else if (draw->side == 1 && draw->ray.y < 0)
		color = data->textures->west.texture[tex_y + 64 * draw->tex_x];
	else if (draw->side == 1 && draw->ray.y > 0)
		color = data->textures->east.texture[tex_y + 64 * draw->tex_x];
	return (color);
}

static unsigned int	get_door_color(t_data *data, t_draw *draw)
{
	int		tex_y;
	int		color;
	char	state;

	color = 0;
	draw->tex_pos += draw->ratio;
	tex_y = (int)draw->tex_pos & (64 - 1);
	state = data->door_map[draw->map.x][draw->map.y];
	if (state != 8)
		color = data->door_frames->sprites[state - 1]
			.texture[tex_y + 64 * draw->tex_x];
	return (color);
}

static void	vertical_line(t_data *data, t_draw draw, int col)
{
	int				row;
	unsigned int	hex;

	row = -1;
	while (++row < WIN_HEIGHT)
	{
		if (row >= draw.draw_start && row <= draw.draw_end)
		{
			if (draw.letter == WALL)
				hex = get_texture_color(data, &draw);
			else if (draw.letter == DOOR)
				hex = get_door_color(data, &draw);
		}
		else if (row > WIN_HEIGHT / 2)
			hex = get_color(*(data->floor_color));
		else
			hex = get_color(*(data->ceiling_color));
		if (draw.letter != DOOR || (hex & 0x00FFFFFF) != 0)
			*(unsigned int *)(data->frame.data_addr
					+ (row * data->frame.size_line + col
						* (data->frame.bits_per_pixel / 8)))
				= hex;
	}
}

void	draw(t_data *data)
{
	int		col;
	t_draw	draw;

	col = -1;
	while (++col < WIN_WIDTH)
	{
		draw = init_draw(data, col, WALL);
		data->z_buffer[col] = perp_wall_dist(draw);
		vertical_line(data, draw, col);
		draw_ceiling(data, draw, col);
		draw = init_draw(data, col, DOOR);
		if (draw.hit)
		{
			vertical_line(data, draw, col);
			draw_ceiling(data, draw, col);
		}
		data->seen_door = 0;
	}
	data->door_distance = 0;
	draw_sprites(data);
	draw_minimap(data);
	mlx_put_image_to_window(data->mlx, data->window,
		data->frame.img_ptr, 0, 0);
}
