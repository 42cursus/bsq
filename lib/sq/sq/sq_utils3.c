/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sq_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:38:33 by abelov            #+#    #+#             */
/*   Updated: 2024/03/12 23:35:31 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sq_utils.h"

void	read_single_file(t_ft_file *fp)
{
	t_baguette				b;
	t_map_legend			l;
	char					buf[MAXC];

	if (!fp)
	{
		ft_putstr_std_err("map error\n");
		return ;
	}
	l = get_legend(read_line(buf, fp)->data);
	if (!l.is_valid)
	{
		ft_putstr_std_err("map error\n");
		return ;
	}
	b = get_solution(parser(ft_read_line_by_line(fp), l));
	ft_putstr(serializer(b));
	ft_putstr("\n");
	serial_killer(b, fp);
}
