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
#include "bsq.h"
#include "config.h"

int	main(int argc, char *argv[])
{
	t_baguette		b;
	t_map_legend	l;

	if (argc < 1)
		return (EX_NOINPUT);
	(void)argv;
	(void)g_map;
	l = get_legend(g_legend_str);
	(void)l;
	b = get_solution(g_b);
	ft_putstr(serializer(b));
	ft_putstr("\n");
	return (EX_OK);
}
