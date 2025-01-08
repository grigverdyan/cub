/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:28:10 by dapetros          #+#    #+#             */
/*   Updated: 2025/01/08 16:28:11 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		print_error_and_exit(WRONG_NUM_ARGS);
	if (!validate_input_file(argv[1]))
		print_error_and_exit(BAD_INPUT_FILE);
	data = data_init();
	parse(argv[1], data);
	if (data->error_code)
		print_error_free_and_exit(data, data->error_code);
	start_game(data);
}
