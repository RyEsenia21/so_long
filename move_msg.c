/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_msg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryesenia <ryesenia@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 17:53:14 by ryesenia          #+#    #+#             */
/*   Updated: 2022/01/29 12:17:50 by mixfon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_msg(t_long *begin)
{
	ft_putstr_fd("Moves counter: ", 1);
	ft_putnbr_fd (begin->steps_count, 1);
	ft_putstr_fd("\n", 1);
}
