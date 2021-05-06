#include "minirt.h"

float	positive_smallest(float a, float b)
{
	if (a < 0)
	{
		if (b > 0)
			return (b);
		return (HUGE_VAL);
	}
	if (b < 0)
	{
		if (a > 0)
			return (a);
		return (HUGE_VAL);
	}
	if (a < b)
		return (a);
	return (b);
}
