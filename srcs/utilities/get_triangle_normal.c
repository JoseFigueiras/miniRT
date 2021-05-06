#include "minirt.h"

t_xyz		get_triangle_normal(t_triangle *triangle, t_xyz point)
{
	t_xyz	vec1;
	t_xyz	vec2;
	t_xyz	normal;

	(void)point;
	vec1 = vec_sub(triangle->point1, triangle->point2);
	vec2 = vec_sub(triangle->point2, triangle->point3);
	normal = cross(vec1, vec2);
	return (normal);
}
