/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_def.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:59:26 by abelov            #+#    #+#             */
/*   Updated: 2023/10/24 16:59:29 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_DEF_H
# define BSQ_DEF_H
# include <stdbool.h>

typedef struct s_sq_pos
{
	int	x;
	int	y;
}			t_sq_pos;

typedef struct s_sq_element_obs
{
	t_sq_pos	pos;
	bool		is_obstacle;
	int			size;

}						t_sq_element;

typedef struct s_baguette
{
	t_sq_pos		size;
	t_sq_element	solution;
	t_sq_element	*map;
}						t_baguette;

#endif //BSQ_DEF_H
