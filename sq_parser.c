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

#include "bsq.h"

//bool	is_legend_valid(t_map_legend l)
//{
//	//if (l.line_count )
//	return (false);
//}
//
//t_map_legend	get_legend(char *str)
//{
//	t_map_legend	l;
//
//
//	l.num_of_rows = buf[0] - '0';
//	l.empty_sym = buf[1];
//	l.obstacle_sym = buf[2];
//	l.bsq_sym = buf[3];
//	is_legend_valid(l);
//
//	return (l);
//}
//
//t_baguette	parse(char **strs)
//{
//	t_baguette		b;
//
//	b.legend = get_legend(strs[0]);
//
//};
//
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
		printf("\"%s\"\n", current->data);
		temp = current;
		current = current->next;
		free(temp->data);
		free(temp);
	}
}
