#include "minirt.h"

static int		apply_reflection(t_line bounce_line, t_scene scene, int color,
					int depth);
static void		init_vars(int *color, float *distance, float *distance_temp);

int	raycast_objs(t_line line, t_scene scene, int depth)
{
	t_objlst	*current;
	int			color;
	int			obj_color;
	float		distance;
	float		distance_temp;

	init_vars(&color, &distance, &distance_temp);
	current = scene.objlst;
	while (current)
	{
		distance_temp = raycast(line, scene, current, &obj_color);
		if (distance_temp < distance)
		{
			distance = distance_temp;
			color = 0;
			color = color_add(color, apply_amb_light(scene, obj_color));
			color = color_add(color, apply_lightlst(scene, current,
						vec_scale(line.vec, distance), obj_color));
			color = apply_reflection(get_bounce_line(current, line, distance),
					scene, color, depth);
		}
		current = current->next;
	}
	return (color);
}

static void	init_vars(int *color, float *distance, float *distance_temp)
{
	*color = create_trgb(0, 0, 0, 0);
	*distance = HUGE_VAL;
	*distance_temp = 0;
}

static int	apply_reflection(t_line bounce_line, t_scene scene, int color,
									int depth)
{
	int	reflect_color;
	int	r;
	int	g;
	int	b;

	if (depth > 0)
	{
		reflect_color = raycast_objs(bounce_line, scene, depth - 1);
		r = (int)((get_r(color) * 0.5) + (get_r(reflect_color) * 0.5));
		g = (int)((get_g(color) * 0.5) + (get_g(reflect_color) * 0.5));
		b = (int)((get_b(color) * 0.5) + (get_b(reflect_color) * 0.5));
		color = create_trgb(0, r, g, b);
	}
	return (color);
}
