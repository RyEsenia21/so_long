/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryesenia <ryesenia@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 17:53:36 by ryesenia          #+#    #+#             */
/*   Updated: 2022/01/29 12:40:54 by mixfon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# define FAIL 1
# define SUCCESS 0
# define A 97
# define D 100
# define S 115
# define W 119
# define RESET "\033[0m"
# define PEACH "\033[38;5;217m"
# define IMG_SIZE 64
# define DOOR "./image/door.xpm"
# define KEY "./image/key.xpm"
# define BACKGROUND "./image/background.xpm"
# define PLAYER "./image/player.xpm"
# define WALL "./image/wall.xpm"
# define CH_DOOR 'E'
# define CH_KEY 'C'
# define CH_BACKGROUND '0'
# define CH_PLAYER 'P'
# define CH_WALL '1'

typedef struct s_long
{
	void	*mlx;
	void	*window;
	char	**map;
	int		fd;
	int		i;
	int		j;
	int		count_p;
	int		count_e;
	int		count_c;
	int		line_len;
	int		count_line;
	int		p_i;
	int		p_j;
	int		steps_count;
	int		collected;
	int		win_height;
	int		win_width;
	int		width;
	int		height;
	void	*image_door;
	void	*image_key;
	void	*image_player;
	void	*image_wall;
	void	*image_background;
}								t_long;

void	ft_putstr_fd(const char *s, int fd);
void	read_map_counting_line(t_long *begin);
void	check_map(int argc, char **argv, t_long *begin);
void	check_rectangle(t_long *begin);
void	check_edges(int line_count, char **map);
void	check_top_bot(int row, char **map);
void	check_chars(t_long *begin);
void	check_argc(int argc, char **argv);
void	open_map(char **argv, t_long *begin);
void	close_map(t_long *begin);
void	print_error(const char *errmsg);
void	read_map(t_long *begin);
void	move_msg(t_long *begin);
void	collect_coins(t_long *begin, char direction);
void	move_player(t_long *begin, char direction);
void	init_map(t_long *begin);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	init_images(t_long *begin);
void	size_window(t_long *begin);
void	put_image(t_long *begin, char c, int i, int j);
void	picture(t_long *begin);
void	hook(t_long *begin);
void	start(t_long *begin);
void	*ft_memset(void *b, int c, size_t len);
int		check_next_tile(t_long *begin, char direction, char tile);
void	win_game(t_long *begin);
int		press_key(int key, t_long *begin);
void	normal_exit(void);

#endif
