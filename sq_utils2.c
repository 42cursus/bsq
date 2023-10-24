#include "sq_utils.h"

int	get_min_size(t_sq_element e1, t_sq_element e2, t_sq_element e3)
{
	int	res;

	if (e1.size <= e2.size && e1.size <= e3.size)
		res = e1.size;
	else if (e2.size <= e1.size && e2.size <= e3.size)
		res = e2.size;
	else
		res = e3.size;
	return (res);
}

void	set_size(t_sq_element *el, t_baguette b)
{
	const t_sq_pos	top = create_pos(el->pos.x, el->pos.y - 1);
	const t_sq_pos	left = create_pos(el->pos.x - 1, el->pos.y);
	const t_sq_pos	diagonal = create_pos(el->pos.x - 1, el->pos.y - 1);
	const int		min_size = get_min_size(
			get_el(top, b),
			get_el(left, b),
			get_el(diagonal, b));

	if (el->is_obstacle == true)
		el->size = 0;
	else
		el->size = min_size + 1;
}
