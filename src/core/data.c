/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:27:16 by dapetros          #+#    #+#             */
/*   Updated: 2025/01/08 16:27:21 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_nulls(t_data *data)
{
	data->map = NULL;
	data->ceiling_color = NULL;
	data->floor_color = NULL;
	data->mlx = NULL;
	data->window = NULL;
	data->textures = NULL;
	data->color_strings = NULL;
	data->texture_paths[_NORTH] = NULL;
	data->texture_paths[_EAST] = NULL;
	data->texture_paths[_WEST] = NULL;
	data->texture_paths[_SOUTH] = NULL;
	data->sprite_distance = NULL;
	data->sprite_order = NULL;
	data->map_sprites = NULL;
}

t_data	*data_init(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		print_error_and_exit(COULD_NOT_INIT);
	set_nulls(data);
	data->error_code = 0;
	data->input_dict = new_dict();
	data->map_list = new_list();
	data->map_height = 0;
	data->map_width = 0;
	data->key_map = (t_key_map){0};
	data->mouse = init_mouse();
	data->seen_door = 0;
	return (data);
}

void	mlx_data_init(t_data *data)
{
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	textures_init(data);
	data->frame.img_ptr = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->frame.data_addr = mlx_get_data_addr(data->frame.img_ptr,
			&data->frame.bits_per_pixel,
			&data->frame.size_line, &data->frame.endian);
}

void	print_data(t_data *data)
{
	t_node	*current;
	int		i;

	i = -1;
	if (!data)
		print_error_and_exit(COULD_NOT_INIT);
	current = data->input_dict->head;
	while (++i < data->input_dict->count)
	{
		printf("key: %s, value %s\n", current->key, current->value);
		current = current->next;
	}
}

t_bool	add_to_data(t_node *data_node, t_data *data)
{
	if (ft_strcmp(data_node->key, "NO"))
		data->texture_paths[_NORTH] = ft_strdup(data_node->value);
	else if (ft_strcmp(data_node->key, "EA"))
		data->texture_paths[_EAST] = ft_strdup(data_node->value);
	else if (ft_strcmp(data_node->key, "WE"))
		data->texture_paths[_WEST] = ft_strdup(data_node->value);
	else if (ft_strcmp(data_node->key, "SO"))
		data->texture_paths[_SOUTH] = ft_strdup(data_node->value);
	else if (ft_strcmp(data_node->key, "F"))
	{
		data->floor_color = new_color(data_node->value);
		if (!data->floor_color)
			return (FALSE);
	}
	else if (ft_strcmp(data_node->key, "C"))
	{
		data->ceiling_color = new_color(data_node->value);
		if (!data->ceiling_color)
			return (FALSE);
	}
	else
		return (FALSE);
	return (TRUE);
}
