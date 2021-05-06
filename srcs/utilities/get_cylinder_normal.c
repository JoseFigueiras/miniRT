#include "minirt.h"

t_xyz		get_cylinder_normal(t_cylinder *cylinder, t_xyz point)
{
	t_xyz	normal;
	t_xyz	center;

	center = cylinder->coords;
	center.z = point.z;
	normal = vec_sub(point, center);
	return (normal);
}
