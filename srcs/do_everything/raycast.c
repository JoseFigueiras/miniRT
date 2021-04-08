#include "minirt.h"

float	raycast(t_line line, t_scene scene, t_objlst *obj, int *color)
{
	char	*type;
	float	ret;

	type = obj->type;
	if (!ft_strcmp(type, "sp"))
		ret = raycast_sphere(line, scene, obj->obj, color);
	else if (!ft_strcmp(type, "pl"))
		ret = raycast_plane(line, scene, obj->obj, color);
	else if (!ft_strcmp(type, "sq"))
		ret = raycast_square(line, scene, obj->obj, color);
	else if (!ft_strcmp(type, "cy"))
		ret = raycast_cylinder(line, scene, obj->obj, color);
	else if (!ft_strcmp(type, "tr"))
		ret = raycast_triangle(line, scene, obj->obj, color);
	return (ret);
}
