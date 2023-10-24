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

void			set_size(t_sq_element *el, t_baguette b);
t_sq_element	create_element(int x, int y, int size, bool is_obstacle);

#endif //SQ_UTILS_H
