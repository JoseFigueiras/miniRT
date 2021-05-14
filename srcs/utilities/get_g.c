#include "minirt.h"

int	get_g(int trgb)
{
	return ((trgb & 0xFF00) >> 8);
}
