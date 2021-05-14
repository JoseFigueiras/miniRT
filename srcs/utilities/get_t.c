#include "minirt.h"

int	get_t(int trgb)
{
	return ((trgb & 0xFF000000) >> 24);
}
