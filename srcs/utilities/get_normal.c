#include "minirt.h"

t_xyz	get_normal(t_objlst *obj, t_xyz point)
{
	t_xyz	normal;
	int		type;

	type = obj->type;
	if (type == SPHERE)
		normal = get_sphere_normal((t_sphere *)obj->obj, point);
	else if (type == PLANE)
		normal = get_plane_normal((t_plane *)obj->obj, point);
	else if (type == SQUARE)
		normal = get_square_normal((t_square *)obj->obj, point);
	else if (type == CYLINDER)
		normal = get_cylinder_normal((t_cylinder *)obj->obj, point);
	else if (type == TRIANGLE)
		normal = get_triangle_normal((t_triangle *)obj->obj, point);
	else
		exit(96);
	return (normal);
}
