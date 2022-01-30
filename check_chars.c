/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryesenia <ryesenia@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 17:52:03 by ryesenia          #+#    #+#             */
/*   Updated: 2022/01/29 12:01:32 by mixfon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void	check_anoder_char(const char c)
{
	if (c == CH_BACKGROUND || c == CH_DOOR || c == CH_KEY
		|| c == CH_WALL || c == CH_PLAYER || c == '\n')
		return ;
	else
		print_error("ANODER CHARS\n");
}

void	check_chars(t_long *begin)
{
	while (begin->map[begin->i] != NULL)
	{
		begin->j = 0;
		while (begin->map[begin->i][begin->j])
		{
			if (begin->map[begin->i][begin->j] == CH_PLAYER)
			{
				begin->count_p++;
				begin->p_i = begin->i;
				begin->p_j = begin->j;
			}
			else if (begin->map[begin->i][begin->j] == CH_DOOR)
				begin->count_e++;
			else if (begin->map[begin->i][begin->j] == CH_KEY)
				begin->count_c++;
			check_anoder_char(begin->map[begin->i][begin->j]);
			begin->j++;
		}		
		begin->i++;
	}
	if (!begin->count_c || !begin->count_e || begin->count_p != 1)
		print_error("INVALID CHARS\n");
}

void	check_top_bot(int row, char **map)
{
	int	i;

	i = 0;
	while (map[row][i] && map[row][i] != '\n')
	{
		if (map[row][i] != '1')
			print_error("INVALID TOP_BOT\n");
		i++;
	}
}

void	check_edges(int line_count, char **map)
{
	int	i;

	i = 1;
	while (i < line_count)
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[0]) - 2] != '1')
			print_error("INVALID EDGES\n");
		i++;
	}
}

void	check_rectangle(t_long *begin)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	begin->line_len = ft_strlen(begin->map[i]) - 1;
	while (begin->map[i])
	{
		j = 0;
		while (begin->map[i][j] && begin->map[i][j] != '\n')
			j++;
		if (j != begin->line_len)
			print_error("INVALID RECTANGLE\n");
		i++;
	}
}
