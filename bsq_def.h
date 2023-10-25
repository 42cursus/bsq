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
	bool	is_valid;
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

/*
 * FT_IO_FILE object type capable of recording all the information needed to
 * control a stream, including its file position indicator, a pointer to its
 * associated buffer (if any), an error indicator that records whether a
 * read/write error has occurred, and an end-of-file indicator that records
 * whether the end of the file has been reached;
 */
typedef struct s_ft_io_file {
	int				_r;
	int				_w;
	int				_offset;
	void			*_cookie;
	int				(*_close)(void*);
	int				(*_read)(void*, char*, int);
	int				(*_write)(void*, const char*, int);
	unsigned char	*ptr;
	short			_flags;
	short			_file;
	struct {
		unsigned char	*base;
		int				size;
	}	s_buf;
	struct {
		unsigned char	*base;
		int				size;
	}	s_line_buf;
}	t_ft_file;

typedef struct s_string_glue {
	char						*data;
	struct s_string_glue		*next;
}	t_string_list_node;

#endif //BSQ_DEF_H
