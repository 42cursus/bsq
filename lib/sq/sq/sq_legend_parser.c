/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sq_legend_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberezhn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:02:46 by yberezhn          #+#    #+#             */
/*   Updated: 2023/10/25 17:30:59 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sq_utils.h"

t_map_legend	set_legend(int num, char *sym, bool is_valid)
{
	t_map_legend	temp;

	temp.num_of_rows = num;
	temp.empty_sym = sym[0];
	temp.obstacle_sym = sym[1];
	temp.bsq_sym = sym[2];
	temp.is_valid = is_valid;
	return (temp);
}

t_map_legend	get_invalid_legend(void)
{
	return (set_legend(0, (char *)"000", false));
}

int	get_num(char *legend, int len)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (i < (len - 3))
		result = result * 10 + (legend[i++] - '0');
	return (result);
}

t_map_legend	get_legend(t_stringlist *node)
{
	char *const		legend = node->data;
	const int		len = ft_strlen(legend);
	int				i;
	t_map_legend	l;

	if (len >= 4)
	{
		i = -1;
		while (++i < len)
		{
			if ((i + 3 < len && !is_numeric(legend[i]))
				|| !is_printable(legend[i]))
			{
				list_free(NULL, node);
				return (get_invalid_legend());
			}
		}
		l = set_legend(get_num(legend, len), &legend[len - 3], true);
	}
	else
		l = get_invalid_legend();
	list_free(NULL, node);
	return (l);
}
