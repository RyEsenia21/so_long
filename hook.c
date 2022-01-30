/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryesenia <ryesenia@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:14:09 by ryesenia          #+#    #+#             */
/*   Updated: 2022/01/29 12:17:44 by mixfon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	normal_exit(void)
{
	ft_putstr_fd("Normal exit\n", 1);
	exit(0);
}

int	close_window(void)
{
	normal_exit();
	return (0);
}

int	press_key(int key, t_long *begin)
{
	if (key == 53)
		normal_exit();
	else if (key == 0)
		move_player(begin, 'a');
	else if (key == 1)
		move_player(begin, 's');
	else if (key == 2)
		move_player(begin, 'd');
	else if (key == 13)
		move_player(begin, 'w');
	picture(begin);
	return (0);
}

void	hook(t_long *begin)
{
	mlx_hook(begin->window, 2, 0xf, press_key, begin);
	mlx_hook(begin->window, 17, 0xf, close_window, NULL);
}
