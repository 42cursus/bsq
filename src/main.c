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
	int	argg;

	argg = 1;
	if (argc < 1)
		return (EX_NOINPUT);
	if (argc > 1)
		while (argg < argc)
			read_single_file(ft_fopen(argv[argg++], "r"));
	else
		read_single_file(ft_fopen("/dev/stdin", "r"));
	return (EX_OK);
}
