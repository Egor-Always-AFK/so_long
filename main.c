/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocapers <ocapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:49:50 by ocapers           #+#    #+#             */
/*   Updated: 2022/04/16 11:58:18 by ocapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init(t_map *map, t_data *data)
{
	int lenght = 0;
	int height = 0;
	t_imgs *img;
	
	data->map = map;
	img = malloc(sizeof(t_imgs));
	if (!img)
		error_message("Error!\n");
	data->imgs = img;
	data->imgs->player_down = mlx_xpm_file_to_image(data->mlx, "./textures/character_down.xpm", &lenght, &height);
	data->imgs->player_up = mlx_xpm_file_to_image(data->mlx, "textures/character_up.xpm", &lenght, &height);
	data->imgs->player_left = mlx_xpm_file_to_image(data->mlx, "textures/character_left.xpm", &lenght, &height);
	data->imgs->player_right = mlx_xpm_file_to_image(data->mlx, "textures/character_right.xpm", &lenght, &height);
	data->imgs->background = mlx_xpm_file_to_image(data->mlx, "textures/floor.xpm", &lenght, &height);
	data->imgs->wall = mlx_xpm_file_to_image(data->mlx, "textures/wall.xpm", &lenght, &height);
	data->imgs->collect = mlx_xpm_file_to_image(data->mlx, "textures/collectibles.xpm", &lenght, &height);
	data->imgs->exit = mlx_xpm_file_to_image(data->mlx, "textures/exit_2.xpm", &lenght, &height);
	data->map->collect = 0;
	data->counter = 0;
}

void map_info(char **argv, t_data *data)
{
	int fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_message("Error!\nI can't open map:c");
	if (ft_strnstr(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 5) == NULL)
		error_message("Error!\nMap has to be .ber\n"); //проверку на .ber.be
	data->length = lenght_count(fd);
	data->height = height_count(fd, data->length);
}

int main(int argc, char **argv)
{
	t_data data;
	t_map map;

	if (argc != 2)
		error_message("Error!\nFew arguments!");
	map_info(argv, &data);
	map.map = ft_calloc(data.height + 1, sizeof(char *));
	data.mlx = mlx_init();
	if (!data.mlx)
		error_message("Error!\nMLX init fail");
	init(&map, &data);
	parse_input(&data, argv);
	data.window = mlx_new_window(data.mlx, data.length * IMG_LENGHT, data.height * IMG_HEIGHT, "./so_long");
	rendering_map(&data);
	mlx_loop(data.mlx);
	return (0);
}