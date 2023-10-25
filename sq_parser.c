/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sq_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberezhn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:02:46 by yberezhn          #+#    #+#             */
/*   Updated: 2023/10/25 17:31:24 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_def.h"
#include "string_utils.h"
#include "sq_utils.h"

bool	is_str_valid(char *str, char *legend)
{
	int		i;
	char	*temp;

	i = 0;
	while (str[i])
	{
		temp = (char [2]){str[i], '\0'};
		if (ft_strcspn(temp, legend) != 0)
			return (false);
	}
	return (true);
}

bool	validate_strs(t_string_list_node *node, t_map_legend l)
{
	const int			first_len = ft_strlen(node->data);
	char				*map_legend_sym;
	t_string_list_node	*current;

	map_legend_sym = (char [3]){l.empty_sym, l.obstacle_sym,  '\0'};
	current = node;
	while (current->next)
	{
		if (ft_strlen(current->data) != first_len
			|| is_str_valid(current->data, map_legend_sym))
			return (false);
		current = current->next;
	}
	return (true);
}

t_baguette	parse(t_string_list_node *node, t_map_legend l)
{
	t_baguette		b;
	t_sq_pos 		size;

	if (!validate_strs(node, l))
		return get_baguette(create_pos(0,0), l, false);
	size = create_pos(ft_strlen(node->data), l.num_of_rows);
	b = get_baguette(size, l, true);
	//b.map = set_map(node, l);
};

