/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chek_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryesenia <ryesenia@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 17:56:11 by ryesenia          #+#    #+#             */
/*   Updated: 2022/01/29 13:42:13 by mixfon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void	read_map_counting_line(t_long *begin)
{
	char	*line;

	line = NULL;
	begin->count_line = 0;
	while (100)
	{	
		line = get_next_line (begin->fd);
		if (line == NULL)
			break ;
		begin->count_line++;
		free(line);
	}
	if (begin->count_line == 0)
		print_error("EMPTY FILE\n");
}

void	close_map(t_long *begin)
{
	close(begin->fd);
}

void	read_map(t_long *begin)
{
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	begin->map = (char **)malloc(sizeof(char *) * (begin->count_line + 1));
	if (!begin->map)
		print_error("ERROR MALLOC");
	while (100)
	{
		line = get_next_line (begin->fd);
		if (line == NULL)
			break ;
		begin->map[i] = line;
		i++;
	}
	begin->map[i] = NULL;
}

void	check_map(int argc, char **argv, t_long *begin)
{
	check_argc(argc, argv);
	open_map(argv, begin);
	read_map_counting_line(begin);
	close_map(begin);
	open_map(argv, begin);
	read_map(begin);
	close_map(begin);
	check_rectangle(begin);
	check_top_bot(0, begin->map);
	check_top_bot(begin->count_line - 1, begin->map);
	check_edges(begin->count_line, begin->map);
	check_chars(begin);
}
