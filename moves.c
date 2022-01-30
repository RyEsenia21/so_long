/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryesenia <ryesenia@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 17:53:23 by ryesenia          #+#    #+#             */
/*   Updated: 2022/01/29 12:18:01 by mixfon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_next_tile(t_long *begin, char direction, char tile)
{
	if ((direction == 'd' && begin->map[begin->p_i][begin->p_j + 1] == tile)
		|| (direction == 'a' && begin->map[begin->p_i][begin->p_j - 1] == tile)
		|| (direction == 's' && begin->map[begin->p_i + 1][begin->p_j] == tile)
		|| (direction == 'w' && begin->map[begin->p_i - 1][begin->p_j] == tile)
		)
		return (SUCCESS);
	else
		return (FAIL);
}

void	win_game(t_long *begin)
{
	mlx_destroy_window(begin->mlx, begin->window);
	begin->window = NULL;
	normal_exit();
}

void	move_player(t_long *begin, char direction)
{
	if (check_next_tile(begin, direction, '1') == SUCCESS)
		return ;
	if (check_next_tile(begin, direction, 'E') == SUCCESS
		&& begin->collected < begin->count_c)
		return ;
	if (check_next_tile(begin, direction, 'C') == SUCCESS)
		begin->collected++;
	begin->map[begin->p_i][begin->p_j] = '0';
	if (direction == 'd')
		begin->p_j++;
	else if (direction == 'a')
		begin->p_j--;
	else if (direction == 's')
		begin->p_i++;
	else if (direction == 'w')
		begin->p_i--;
	begin->steps_count++;
	move_msg(begin);
	if (begin->collected == begin->count_c
		&& begin->map[begin->p_i][begin->p_j] == 'E')
		win_game(begin);
	begin->map[begin->p_i][begin->p_j] = 'P';
}
