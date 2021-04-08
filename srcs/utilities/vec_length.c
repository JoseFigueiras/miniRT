#include "minirt.h"

float	vec_length(t_xyz vec)
{
	float	x;
	float	y;
	float	z;
	float	ret;

	x = vec.x;
	y = vec.y;
	z = vec.z;
	ret = sqrt((x * x) + (y * y) + (z * z));
	return (ret);
}
