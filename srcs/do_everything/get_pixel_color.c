#include "minirt.h"

int	get_pixel_color(int x, int y, t_scene scene)
{
	t_line		line;
	int			color;

	line = get_line(x, y, scene);
	color = raycast_objs(line, scene);
	return (color);
}
