#include "minirt.h"

float		raycast_plane(t_line line, t_scene scene,
							t_plane *plane, int *color)
{
	float	n;
	float	d;
	float	distance;

	(void)scene;
	n = plane->vec.x * (plane->coords.x - line.point.x)
		+ plane->vec.y * (plane->coords.y - line.point.y)
		+ plane->vec.z * (plane->coords.z - line.point.z);
	d = plane->vec.x * line.vec.x
		+ plane->vec.y * line.vec.y
		+ plane->vec.z * line.vec.z;
	distance = (n / d);
	if (distance > 0)
	{
		*color = plane->color;
		return (distance);
	}
	return (HUGE_VAL);
}
