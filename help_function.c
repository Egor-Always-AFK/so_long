/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocapers <ocapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:22:28 by ocapers           #+#    #+#             */
/*   Updated: 2022/04/16 11:50:24 by ocapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int exit_function(t_data *data)
{
	mlx_destroy_window(data->mlx, data->window);
	printf("DELETE THE GAME!");
	printf("\nWork harder!\n");
	exit(0);
}

int win_message(t_data *data)
{
	mlx_destroy_window(data->mlx, data->window);
	printf("You won!!");
	printf("\nCongratulations\n");
	exit (0);
}