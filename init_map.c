/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryesenia <ryesenia@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 17:52:35 by ryesenia          #+#    #+#             */
/*   Updated: 2022/01/29 13:39:28 by mixfon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_long *begin)
{
	ft_memset(begin, 0, sizeof(t_long));
	begin->height = IMG_SIZE;
	begin->width = IMG_SIZE;
}
