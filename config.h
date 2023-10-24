#include "bsq_def.h"

#ifndef CONFIG_H
#define CONFIG_H

static const t_sq_element	g_sq_ary[16] = {
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

static char	g_map[] =
#include "test/map.txt"
;

static const int g_sq_ary_len = 16;

#endif //CONFIG_H
