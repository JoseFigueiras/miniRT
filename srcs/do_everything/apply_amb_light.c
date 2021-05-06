#include "minirt.h"

int	apply_amb_light(t_scene scene, int color)
{
	int		r;
	int		g;
	int		b;
	t_amb	amb;

	//product = dot(vec, bounce);
	//product = (((product + 1) / 2) + 1) / 2;//shift range from [-1, 1] to [.5, 1]
	amb = *(scene.amb);
	r = (int)(get_r(color) * (amb.brightness * get_r(amb.color)) / 200);
	g = (int)(get_g(color) * (amb.brightness * get_g(amb.color)) / 200);
	b = (int)(get_b(color) * (amb.brightness * get_b(amb.color)) / 200);
	return(create_trgb(0, r, g, b));
}
