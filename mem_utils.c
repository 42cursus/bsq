#include "bsq_def.h"
#include "bsq.h"

t_sq_element	*alloc_empty_map(int size)
{
	t_sq_element	*map;

	map = malloc(sizeof(t_sq_element) * size);
	if (!map)
		return (NULL);
	ft_memset(map, 0, sizeof(t_sq_element) * size);
	return (map);
}
