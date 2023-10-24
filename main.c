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

int	main(int argc, char *argv[])
{
	char *str;

	if (argc < 1)
		return (EX_NOINPUT);
	(void)argv;

	str = ft_strdup(g_map);
	ft_putstr(str);

	return (EX_OK);
}
