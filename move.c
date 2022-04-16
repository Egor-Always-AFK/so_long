/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocapers <ocapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:37:38 by ocapers           #+#    #+#             */
/*   Updated: 2022/04/16 11:51:59 by ocapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int search_solution(int key_code, t_data *data)
{
	if (key_code == ESC)
		exit_function(data);
	else if (key_code == UP_KEY)
		player_move_up(data);
	else if (key_code == DOWN_KEY)
		player_move_down(data);
	else if (key_code == RIGHT_KEY)
		player_move_right(data);
	else if (key_code == LEFT_KEY)
		player_move_left(data);
	return (0);
}

void player_move_down(t_data *data)
{
	int x;
	int y;

	x = data->player.pos_x;
	y = data->player.pos_y;
	if (data->map->map[y + 1][x] != '1')
	{
		if (data->map->map[y][x] == 'C')
		{
			data->map->map[y][x] = '0';
			data->player.collect += 1;
		}
		mlx_put_image_to_window(data->mlx, data->window, data->imgs->player_down, x * 32, (y + 1) * 32);
		if (data->map->map[y + 1][x] == 'E' && data->map->collect == data->player.collect)
			win_message(data);
		else if (data->map->map[y][x] == 'E')
			mlx_put_image_to_window(data->mlx, data->window, data->imgs->exit, x * 32, y * 32);
		else
			mlx_put_image_to_window(data->mlx, data->window, data->imgs->background, x * 32, y * 32);
		data->player.pos_y = data->player.pos_y + 1;
	}
	else
		mlx_put_image_to_window(data->mlx, data->window, data->imgs->player_down, x * 32, y * 32);
}

void player_move_up(t_data *data)
{
	int x;
	int y;

	x = data->player.pos_x;
	y = data->player.pos_y;
	if (data->map->map[y - 1][x] != '1')
	{
		if (data->map->map[y][x] == 'C')
		{
			data->map->map[y][x] = '0';
			data->player.collect += 1;
		}
		mlx_put_image_to_window(data->mlx, data->window, data->imgs->player_up, x * 32, (y - 1) * 32);
		if (data->map->map[y - 1][x] == 'E' && data->player.collect == data->map->collect)
			win_message(data);
		else if (data->map->map[y][x] == 'E')
			mlx_put_image_to_window(data->mlx, data->window, data->imgs->exit, x * 32, y * 32);
		else
			mlx_put_image_to_window(data->mlx, data->window, data->imgs->background, x * 32, y * 32);
		data->player.pos_y = data->player.pos_y - 1;
	}
	else
		mlx_put_image_to_window(data->mlx, data->window, data->imgs->player_up, x * 32, y * 32);
}

void player_move_right(t_data *data)
{
	int x;
	int y;

	x = data->player.pos_x;
	y = data->player.pos_y;
	if (data->map->map[y][x + 1] != '1')
	{
		if (data->map->map[y][x] == 'C')
		{
			data->map->map[y][x] = '0';
			data->player.collect += 1;
		}
		mlx_put_image_to_window(data->mlx, data->window, data->imgs->player_right, (x + 1) * 32, y * 32);
		if (data->map->map[y][x + 1] == 'E' && data->map->collect == data->player.collect)
			win_message(data);
		else if (data->map->map[y][x] == 'E')
			mlx_put_image_to_window(data->mlx, data->window, data->imgs->exit, x * 32, y * 32);
		else
			mlx_put_image_to_window(data->mlx, data->window, data->imgs->background, x * 32, y * 32);
		data->player.pos_x = data->player.pos_x + 1;
	}	
	else
		mlx_put_image_to_window(data->mlx, data->window, data->imgs->player_right, x * 32, y * 32);
}

void player_move_left(t_data *data)
{
	int x;
	int y;

	x = data->player.pos_x;
	y = data->player.pos_y;
		if (data->map->map[y][x - 1] != '1')
		{
		if (data->map->map[y][x] == 'C')
		{
			data->map->map[y][x] = '0';
			data->player.collect += 1;
		}
			mlx_put_image_to_window(data->mlx, data->window, data->imgs->player_left, (x - 1) * 32, y * 32);
			if (data->map->map[y][x - 1] == 'E' && data->player.collect == data->map->collect)
				win_message(data);
			else if (data->map->map[y][x] == 'E')
				mlx_put_image_to_window(data->mlx, data->window, data->imgs->exit, x * 32, y * 32);
			else
				mlx_put_image_to_window(data->mlx, data->window, data->imgs->background, x * 32, y * 32);
			data->player.pos_x = data->player.pos_x - 1;
		}
		else
			mlx_put_image_to_window(data->mlx, data->window, data->imgs->player_left, x * 32, y * 32);
}