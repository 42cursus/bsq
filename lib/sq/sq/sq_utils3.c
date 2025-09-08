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
	t_baguette		b;
	t_map_legend	l;
	char			*str;
	char			buf[MAXC];
	t_stringlist	*list;

	if (!fp)
		return ((void) ft_putstr_std_err("map error\n"));
	l = get_legend(read_line(buf, fp));
	if (!l.is_valid)
	{
		ft_fclose(fp);
		free(fp);
		return ((void) ft_putstr_std_err("map error\n"));
	}
	list = ft_read_line_by_line(fp);
	b = get_solution(parser(list, l));
	str = serializer(b);
	ft_putstr(str);
	ft_putstr("\n");
	free(str);
	serial_killer(b, fp, list);
}
