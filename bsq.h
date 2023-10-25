/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:04:58 by abelov            #+#    #+#             */
/*   Updated: 2023/10/24 17:05:00 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# include "bsq_def.h"
# include "file_utils.h"
# include "string_utils.h"

//t_baguette	parse(char *buf);
t_map_legend	get_legend(char *legend);
t_baguette		get_solution(t_baguette b);
char			*serializer(t_baguette b);
t_baguette		parser(t_string_list_node *node, t_map_legend l);
void			do_main(t_ft_file *fp, t_string_list_node *head);
#endif //BSQ_H