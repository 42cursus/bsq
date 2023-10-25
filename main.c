/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 22:50:54 by abelov            #+#    #+#             */
/*   Updated: 2023/10/23 22:50:57 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sysexits.h>
#include "config.h"
#include "bsq.h"

static const char		*g_filename = "../../bsq/test/map.h";

int	main(int argc, char *argv[])
{
	t_baguette				b;
	t_map_legend			l;
	t_ft_file				*fp;
	int						flag;
	t_string_list_node		*head;

	if (argc < 1)
		return (EX_NOINPUT);
	(void)argv;
	(void)g_map;
	l = get_legend(g_legend_str);
	(void)l;
	b = get_solution(g_b);
	ft_putstr(serializer(b));
	ft_putstr("\n");
	fp = ft_fopen(g_filename, "r");
	if (!fp)
		return (1);
	flag = 0;
	head = ft_read_line_by_line(fp);
	if (flag != EX_OK)
		return (flag);
	do_main(fp, head);
	return (EX_OK);
}
