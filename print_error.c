/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryesenia <ryesenia@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 18:08:15 by ryesenia          #+#    #+#             */
/*   Updated: 2022/01/28 21:08:07 by ryesenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(const char *errmsg)
{
	ft_putstr_fd(errmsg, 2);
	ft_putstr_fd("Use:\n./so_long name_file.ber\n", 2);
	exit(-1);
}

void	check_argc(int argc, char **argv)
{
	size_t	len;

	len = 0;
	if (argc != 2)
		print_error("Invalid number of arguments\n");
	if (argv[1][0] == '\0')
		print_error("Invalid file name\n");
	len = ft_strlen(argv[1]);
	if (len < 5)
		print_error("Invalid name\n");
	if (argv[1][len - 1] != 'r' || argv[1][len - 2] != 'e'
		|| argv[1][len - 3] != 'b' || argv[1][len - 4] != '.')
		print_error("Probably the file extension\n");
}

void	open_map(char **argv, t_long *begin)
{
	begin->fd = open(argv[1], O_RDONLY);
	if (begin->fd == -1)
	{
		ft_putstr_fd(argv[1], 2);
		print_error("  IS INVALID\n");
	}
}

int	main(int argc, char **argv)
{
	t_long	begin;

	init_map(&begin);
	check_map(argc, argv, &begin);
	start(&begin);
	return (0);
}
