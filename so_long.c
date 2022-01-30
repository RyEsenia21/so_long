/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryesenia <ryesenia@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:55:21 by ryesenia          #+#    #+#             */
/*   Updated: 2022/01/29 13:24:26 by mixfon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_long *begin, char c, int i, int j)
{
	void	*image;

	image = NULL;
	if (c == CH_DOOR)
		image = begin->image_door;
	else if (c == CH_KEY)
		image = begin->image_key;
	else if (c == CH_WALL)
		image = begin->image_wall;
	else if (c == CH_PLAYER)
		image = begin->image_player;
	else if (c == CH_BACKGROUND)
		image = begin->image_background;
	mlx_put_image_to_window(begin->mlx, begin->window, begin->image_background,
		j * IMG_SIZE, i * IMG_SIZE);
	mlx_put_image_to_window(begin->mlx, begin->window, image,
		j * IMG_SIZE, i * IMG_SIZE);
}

void	picture(t_long *begin)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < begin->count_line)
	{
		j = 0;
		while (j < begin->line_len)
		{
			put_image(begin, begin->map[i][j], i, j);
			j++;
		}
		i++;
	}
}

void	size_window(t_long *begin)
{
	begin->win_width = begin->line_len * IMG_SIZE;
	begin->win_height = begin->count_line * IMG_SIZE;
}

void	start(t_long *begin)
{
	size_window(begin);
	begin->mlx = mlx_init();
	begin->window = mlx_new_window(begin->mlx,
			begin->win_width, begin->win_height, "so_long");
	init_images(begin);
	picture(begin);
	hook(begin);
	mlx_loop(begin->mlx);
}

void	init_images(t_long *begin)
{
	begin->image_door = mlx_xpm_file_to_image(begin->mlx, DOOR,
			&begin->width, &begin->height);
	begin->image_key = mlx_xpm_file_to_image(begin->mlx, KEY,
			&begin->width, &begin->height);
	begin->image_wall = mlx_xpm_file_to_image(begin->mlx, WALL,
			&begin->width, &begin->height);
	begin->image_background = mlx_xpm_file_to_image(begin->mlx, BACKGROUND,
			&begin->width, &begin->height);
	begin->image_player = mlx_xpm_file_to_image(begin->mlx, PLAYER,
			&begin->width, &begin->height);
}
