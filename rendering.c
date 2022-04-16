/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocapers <ocapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 18:47:40 by ocapers           #+#    #+#             */
/*   Updated: 2022/04/15 19:42:24 by ocapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void rendering_map(t_data *data)
{
    int y;
    int x;

    y = 0;
    while (y < data->height)
    {
        x = 0;
        while (x < data->length)
        {
            if (data->map->map[y][x] == 'P')
            {
                mlx_put_image_to_window(data->mlx, data->window, data->imgs->player_down, x * 32, y * 32);
                data->player.pos_x = x;
                data->player.pos_y = y;
            }
            else if (data->map->map[y][x] == 'C')
                mlx_put_image_to_window(data->mlx, data->window, data->imgs->collect, x * 32, y * 32);
            else if (data->map->map[y][x] == '1')
                mlx_put_image_to_window(data->mlx, data->window, data->imgs->wall, x * 32, y * 32);
            else if (data->map->map[y][x] == 'E')
                mlx_put_image_to_window(data->mlx, data->window, data->imgs->exit, x * 32, y * 32);
            else
                mlx_put_image_to_window(data->mlx, data->window, data->imgs->background, x * 32, y * 32);
            x++;
        }
        y++;
    }
    mlx_hook(data->window, 17, 1L << 2, exit_function, data);
    mlx_key_hook(data->window, search_solution, data);
}