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
	t_baguette				baguette;
	char					buf[MAXC];
	t_stringlist		*list;

	if (!fp)
		return ((void) ft_putstr_std_err("map error\n"));
	t_stringlist *node = read_line(buf, fp);
	l = get_legend(node->data);
	free(node->data);
	free(node);
	if (!l.is_valid)
		return ((void) ft_putstr_std_err("map error\n"));
	list = ft_read_line_by_line(fp);
	baguette = parser(list, l);
	b = get_solution(baguette);
	char *str = serializer(b);
	ft_putstr(str);
	ft_putstr("\n");
	free(str);
	serial_killer(b, fp, list);
}
