#include "minirt.h"

int	apply_amb_light(t_scene scene, int color)
{
	int		r;
	int		g;
	int		b;
	t_amb	amb;

	amb = *(scene.amb);
	r = (int)(get_r(color) * (amb.brightness * get_r(amb.color)) / 200);
	g = (int)(get_g(color) * (amb.brightness * get_g(amb.color)) / 200);
	b = (int)(get_b(color) * (amb.brightness * get_b(amb.color)) / 200);
	return (create_trgb(0, r, g, b));
}
