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

static const char		*g_filename = "../../bsq/test/map2.txt";

int	main(int argc, char *argv[])
{
	t_baguette				b;
	t_map_legend			l;
	t_ft_file				*fp;
	t_string_list_node		*head;

	if (argc < 1)
		return (EX_NOINPUT);
	(void)argv;

	ft_putstr("\n");
	fp = ft_fopen(g_filename, "r");
	if (!fp)
		return (1);

	char				buf[MAXC];
	t_string_list_node	*node;
	node = read_line(buf, fp);

	l = get_legend(node->data);
	if (!l.is_valid)
		ft_putstr_std_err("map error\n");
	head = ft_read_line_by_line(fp);
	b = parser(head, l);
	ft_putstr(serializer(b));
	//c = get_solution(b);
	//ft_putstr(serializer(c));
	(void)b;
	do_main(fp, head);
	return (EX_OK);
}
