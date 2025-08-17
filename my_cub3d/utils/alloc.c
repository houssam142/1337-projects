#include "../include/cub3d.h"

void	ft_alloc_str(t_parse *data, int k, char c)
{
    if (c == 'F')
		data->floor_color = malloc(k + 1);
    else if (c == 'C')
        data->celing_color = malloc(k + 1);
    else if (c == 'E')
        data->path_e = malloc(k + 1);
    else if (c == 'W')
        data->path_w = malloc(k + 1);
    else if (c == 'N')
        data->path_n = malloc(k + 1);
    else if (c == 'S')
        data->path_s = malloc(k + 1);
}
