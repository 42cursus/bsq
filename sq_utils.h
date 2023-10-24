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
# include <stddef.h>

void	set_size(t_sq_element *el, t_baguette b);
t_sq_element	get_el(t_sq_pos pos, t_baguette b);
#endif //SQ_UTILS_H
