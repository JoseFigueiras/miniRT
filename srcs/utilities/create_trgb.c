#include "minirt.h"

int	create_trgb(int t, int r, int g, int b)
{
	if (t > 255)
		t = 255;
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	return (t << 24 | r << 16 | g << 8 | b);
}
