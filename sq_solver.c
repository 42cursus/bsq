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

t_baguette	fill_all_sizes(t_baguette b)
{
	int	i;

	i = 0;
	while (i < b.map_arr_size)
	{
		set_size(&b.map[i], b);
		if (b.map[i].size > b.solution.size)
			b.solution = b.map[i];
		i++;
	}
	return (b);
}

t_baguette	get_solution(t_baguette b)
{
	t_baguette		baguette;
	t_sq_element	s;
	t_sq_element	temp;

	baguette = fill_all_sizes(b);
	if (baguette.solution.is_obstacle == false)
	{
		s = baguette.solution;
		temp = create_element(s.pos.x - (s.size - 1),
				s.pos.y - (s.size - 1),
				s.size, s.is_obstacle);
		baguette.solution = temp;
	}
	return (baguette);
}

bool	is_bsq(t_baguette b, int i)
{
	t_sq_pos	p;

	p.y = i / b.size.y;
	p.x = i % b.size.y;
	if ((p.y >= b.solution.pos.y)
		&& (p.y <= (b.solution.pos.y + b.solution.size))
		&& ((p.x >= b.solution.pos.x)
			&& (p.x <= (b.solution.pos.x + b.solution.size))))
		return (true);
	return (false);
}

char	*serializer(t_baguette b)
{
	int			i;
	char		*str;
	char		c;
	int			size;

	i = 0;
	size = b.map_arr_size + b.size.y + 1;
	str = ft_empty_string(size);
	while (i < b.map_arr_size)
	{
		c = b.legend.empty_sym;
		if ((i > 0) && (i % b.size.y) == 0)
			ft_strlcat(str, "\n", size);
		if (b.map[i].is_obstacle)
			c = b.legend.obstacle_sym;
		else if (is_bsq(b, i))
			c = b.legend.bsq_sym;
		ft_strlcat(str, (char [2]){c, '\0'}, size);
		i++;
	}
	return (str);
}

char	*serial_killer(t_baguette baguette)
{
	(void)baguette;
	return (NULL);
}
