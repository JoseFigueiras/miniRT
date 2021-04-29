#include "minirt.h"

static void	apply_amb_light(t_scene scene, int *color);

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
	apply_amb_light(scene, color);
	return (ret);
}

static void	apply_amb_light(t_scene scene, int *color)
{
	int		r;
	int		g;
	int		b;
	t_amb	amb;

	amb = *(scene.amb);
	r = amb.brightness * (get_r(amb.color) * 3 / 10) + (get_r(*color) * 7 / 10);
	g = amb.brightness * (get_g(amb.color) * 3 / 10) + (get_g(*color) * 7 / 10);
	b = amb.brightness * (get_b(amb.color) * 3 / 10) + (get_b(*color) * 7 / 10);
	*color = create_trgb(0, r, g, b);
}
