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

#include "sq_utils.h"

bool	is_str_valid(char *str, t_map_legend l)
{
	int			i;
	char		*temp;
	char		*map_legend_sym;

	map_legend_sym = (char [3]){l.empty_sym, l.obstacle_sym, '\0'};
	i = 0;
	while (str[i])
	{
		temp = (char [2]){str[i], '\0'};
		if (ft_strcspn(temp, map_legend_sym) != 0)
			return (false);
		i++;
	}
	return (true);
}

bool	validate_strs(t_string_list_node *node, t_map_legend l)
{
	const int			first_len = ft_strlen(node->data);
	t_string_list_node	*current;

	current = node;
	while (current)
	{
		if (ft_strlen(current->data) != first_len
			|| !is_str_valid(current->data, l))
			return (false);
		current = current->next;
	}
	return (true);
}

t_sq_element	*set_map(t_string_list_node *node, t_baguette b)
{
	int		i;
	int		j;
	int		k;
	char	c;
	char	csym;

	i = 0;
	k = 0;
	while (i < b.size.y)
	{
		j = 0;
		while (j < b.size.x)
		{
			c = node->data[j];
			csym = b.legend.obstacle_sym;
			b.map[k] = create_element(j, i, 0, c == csym);
			j++;
			k++;
		}
		node = node->next;
		i++;
	}
	return (b.map);
}

t_baguette	parser(t_string_list_node *node, t_map_legend l)
{
	t_baguette		b;
	t_sq_pos		size;

	if (!validate_strs(node, l))
		return (get_baguette(create_pos(0, 0), l, false));
	size = create_pos(ft_strlen(node->data), l.num_of_rows);
	b = get_baguette(size, l, true);
	b.map = set_map(node, b);
	return (b);
}

void	do_main(t_ft_file *fp, t_string_list_node *head)
{
	size_t				line_num;
	t_string_list_node	*current;
	t_string_list_node	*temp;

	line_num = 0;
	if (fp != (t_ft_file *)stdin)
		ft_fclose(fp);
	current = head;
	while (current)
	{
		line_num++;
		temp = current;
		current = current->next;
		free(temp->data);
		free(temp);
	}
}
