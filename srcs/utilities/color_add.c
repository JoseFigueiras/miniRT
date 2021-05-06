#include "minirt.h"

int	color_add(int color1, int color2)
{
	int	r;
	int	g;
	int	b;

	r = get_r(color1) + get_r(color2);
	g = get_g(color1) + get_g(color2);
	b = get_b(color1) + get_b(color2);
	return (create_trgb(0, r, g, b));
}
