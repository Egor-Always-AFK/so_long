/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocapers <ocapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:14:21 by ocapers           #+#    #+#             */
/*   Updated: 2022/04/10 18:13:57 by ocapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void error_message(char *message)
{
    ft_putstr_fd(message, 2);
    exit (1);    
}

int counter_for_map(char *s, char c)
{
    int i;
    int ret;

    i = 0;
    ret = 0;

    while (s && s[i])
        if (s[i++] == c)
            ret++;
    return (ret);
}