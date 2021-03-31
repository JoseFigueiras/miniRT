#include "minirt.h"

int	get_r(int trgb)
{
	return(trgb & (0xFF << 16));
}
