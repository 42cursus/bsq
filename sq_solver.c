/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_sq_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:06:23 by abelov            #+#    #+#             */
/*   Updated: 2023/10/24 17:06:25 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sq_utils.h"
#include "string_utils.h"


void	fill_all_sizes(t_baguette b)
{
	int	i;

	i = 0;
	while (i <= b.map_arr_size)
	{
		set_size(&b.map[i], b);
		i++;
	}
}

t_baguette	get_solution(t_baguette b)
{
	fill_all_sizes(b);
	return (b);
}

char	*serializer(t_baguette b)
{
	int		i;
	char	*str;
	char	c;

	i = 0;
	str = ft_empty_string(b.map_arr_size + b.size.y + 1);
	while (i < b.map_arr_size)
	{
		c = '.';
		if (b.map[i].is_obstacle)
			c = 'o';
		else if (b.map[i].is_obstacle)
			c = 'x';
		ft_strlcat(str, &c, 1);
		i++;
	}
	return (str);
}

char	*serial_killer(t_baguette baguette)
{
	(void)baguette;
	return (NULL);
}
