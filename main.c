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
	//t_context	c;

	if (argc < 1)
		return (EX_NOINPUT);
	(void)argv;
	//c = parse(g_map);
	get_solution(g_b);
	ft_putstr(serializer(g_b));
	(void)g_map;
	return (EX_OK);
}
