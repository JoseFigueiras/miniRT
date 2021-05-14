#include "minirt.h"

float	raycast_square(t_line line, t_scene scene,
						t_square *square, int *color)
{
	float	n;
	float	d;
	float	distance;
	t_xyz	intersect;

	(void)scene;
	n = square->vec.x * (square->coords.x - line.point.x)
		+ square->vec.y * (square->coords.y - line.point.y)
		+ square->vec.z * (square->coords.z - line.point.z);
	d = square->vec.x * line.vec.x
		+ square->vec.y * line.vec.y
		+ square->vec.z * line.vec.z;
	distance = (n / d);
	if (distance > 0)
	{
		intersect = vec_add(line.point, vec_scale(line.vec, distance));
		if (intersect.z < square->coords.z + square->side / 2
			&& intersect.z > square->coords.z - square->side / 2)
		{
			*color = square->color;
			return (distance);
		}
	}
	return (HUGE_VAL);
}
