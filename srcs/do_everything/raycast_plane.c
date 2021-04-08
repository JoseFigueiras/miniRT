#include "minirt.h"

float		raycast_plane(t_line line, t_scene scene,
							t_plane *plane, int *color)
{
	float	t;
	t_xyz	intersect;
	t_xyz	cam_coords;

	cam_coords = scene.camlst->coords;
	t = -1 * ((line.point.y - plane->coords.y) / line.vec.y);
	if (t > 0 && t != HUGE_VAL)
	{
		intersect.x = (line.point.x + line.vec.x) * t;
		intersect.y = (line.point.y + line.vec.y) * t;
		intersect.z = (line.point.z + line.vec.z) * t;
		*color = plane->color;
		return (points_distance(cam_coords, intersect));
	}
	return (0);
}
