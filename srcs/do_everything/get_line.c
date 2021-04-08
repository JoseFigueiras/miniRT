#include "minirt.h"

t_line	get_line(int x, int y, t_scene scene)
{
	t_line	line;
	float	fov;

	fov = (float)scene.camlst->fov;

	line.point = scene.camlst->coords;
	line.vec.z = -1 / tan(to_radians(fov));
	//TODO vec.x vec.y
	return (line);
}
