#include <stdbool.h>

#ifndef FT_DEF_H
# define FT_DEF_H

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

#endif //FT_DEF_H
