/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sq_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberezhn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:02:46 by yberezhn          #+#    #+#             */
/*   Updated: 2023/10/24 19:02:51 by yberezhn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQ_UTILS_H
# define SQ_UTILS_H
# include "bsq_def.h"
#include "mem_utils.h"
# include <stddef.h>
# include <stdbool.h>

t_sq_pos		create_pos(int x, int y);
t_sq_element	get_el(t_sq_pos pos, t_baguette b);
void			set_size(t_sq_element *el, t_baguette b);
int				get_min_size(t_sq_element e1, t_sq_element e2, t_sq_element e3);
t_baguette		get_baguette(t_sq_pos size, t_map_legend l, bool v);
t_sq_element	create_element(int x, int y, int size, bool is_obstacle);
#endif //SQ_UTILS_H
