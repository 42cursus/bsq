#include <stdbool.h>
#include "ft_def.h"


t_sq_element create_element(int x, int y, bool is_obstacle)
{
	t_sq_element temp;

	temp.pos.x = x;
	temp.pos.y = y;
	temp.is_obstacle = is_obstacle;
	return (temp);
};

t_sq_pos create_pos(int x, int y)
{
	t_sq_pos temp;

	temp.x = x;
	temp.y = y;
	return (temp);
};

int get_el_size_by_pos(int x, int y)
{
	if (x < 0 || y < 0)
		return (0);
};

void set_size(t_sq_element el, int size)
{
	//TODO
	el.size = size;

}