#include "minirt.h"

t_xyz	get_sphere_normal(t_sphere *sphere, t_xyz point)
{
	t_xyz	normal;

	normal = vec_sub(point, sphere->coords);
	return (normal);
}
