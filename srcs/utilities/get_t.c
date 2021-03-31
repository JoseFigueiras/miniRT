#include "minirt.h"

int	get_t(int trgb)
{
	return(trgb & (0xFF << 24));
}
