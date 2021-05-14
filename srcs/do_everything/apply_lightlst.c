#include "minirt.h"

static int		light_raycast_objs(t_scene scene, t_line line, t_objlst *obj);
static int		apply_light(t_lightlst *light, t_xyz point, t_objlst *obj,
					int color);
static float	local_get_product(t_lightlst *light, t_xyz point,
					t_objlst *obj);

int	apply_lightlst(t_scene scene, t_objlst *obj, t_xyz point, int obj_color)
{
	t_lightlst	*current;
	t_line		line;
	int			has_shadow;
	int			color;

	color = 0;
	current = scene.lightlst;
	while (current)
	{
		line.point = current->coords;
		line.vec = normalize_vec(vec_sub(point, current->coords));
		has_shadow = light_raycast_objs(scene, line, obj);
		if (!has_shadow)
		{
			color = color_add(color, apply_light(current, point, obj,
						obj_color));
		}
		current = current->next;
	}
	return (color);
}

static int	light_raycast_objs(t_scene scene, t_line line, t_objlst *obj)
{
	int			useless;
	t_objlst	*current;
	t_objlst	*closest;
	float		distance;
	float		distance_temp;

	distance = HUGE_VAL;
	distance_temp = 0;
	current = scene.objlst;
	while (current)
	{
		distance_temp = raycast(line, scene, current, &useless);
		if (distance_temp < distance)
			closest = current;
		current = current->next;
	}
	if (closest == obj)
		return (0);
	return (1);
}

static int	apply_light(t_lightlst *light, t_xyz point, t_objlst *obj,
						int color)
{
	int		r;
	int		g;
	int		b;
	float	distance;
	float	product;

	product = local_get_product(light, point, obj);
	distance = vec_length(vec_sub(light->coords, point));
	if (distance < 1)
		distance = 1.0f;
	r = (int)(get_r(color) * (get_r(light->color)
				* light->brightness * product / distance) / 200);
	g = (int)(get_g(color) * (get_g(light->color)
				* light->brightness * product / distance) / 200);
	b = (int)(get_b(color) * (get_b(light->color)
				* light->brightness * product / distance) / 200);
	return (create_trgb(0, r, g, b));
}

static float	local_get_product(t_lightlst *light, t_xyz point,
									t_objlst *obj)
{
	float	product;
	t_xyz	vec;
	t_line	line;
	t_line	bounce;
	float	distance;

	vec = vec_sub(point, light->coords);
	line.point = light->coords;
	line.vec = vec;
	distance = vec_length(vec);
	bounce = get_bounce_line(obj, line, distance);
	product = dot(normalize_vec(vec), bounce.vec);
	product = (((product + 1) / 2) + 0.5) / 2;
	return (product);
}
