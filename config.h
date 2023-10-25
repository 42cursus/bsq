/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:58:23 by abelov            #+#    #+#             */
/*   Updated: 2023/10/24 16:58:27 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H
# include "bsq_def.h"
# include "sq_utils.h"
# include "test/map.h"

static t_sq_element		g_sq_ary[] = {
{{0, 0}, true, 0},
{{1, 0}, false, 0},
{{2, 0}, false, 0},
{{3, 0}, false, 0},
{{0, 1}, false, 0},
{{1, 1}, false, 0},
{{2, 1}, false, 0},
{{3, 1}, false, 0},
{{0, 2}, true, 0},
{{1, 2}, false, 0},
{{2, 2}, false, 0},
{{3, 2}, false, 0},
{{0, 3}, false, 0},
{{1, 3}, false, 0},
{{2, 3}, false, 0},
{{3, 3}, false, 0}
};

static const t_baguette	g_b = {
{4, 4},
	16,
	get_el,
{{0, 0}, true, 0},
{4, '.', 'o', 'x'},
	g_sq_ary
};

#endif //CONFIG_H
