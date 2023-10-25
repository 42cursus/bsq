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

typedef struct s_sq_element
{
	t_sq_pos	pos;
	bool		is_obstacle;
	int			size;
}						t_sq_element;

typedef struct s_bsq_el
{
	struct s_sq_element	base;
	bool				is_bsq;
}						t_bsq_el;

typedef struct s_map_legend
{
	int		num_of_rows;
	char	empty_sym;
	char	obstacle_sym;
	char	bsq_sym;
}						t_map_legend;

typedef struct s_baguette
{
	t_sq_pos		size;
	int				map_arr_size;
	t_sq_element	(*get_el)(t_sq_pos, struct s_baguette);
	t_sq_element	solution;
	t_map_legend	legend;
	t_sq_element	*map;
}						t_baguette;

#endif //BSQ_DEF_H
