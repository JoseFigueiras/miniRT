#include "minirt.h"

t_xyz	rotate_x(t_xyz vec, float degrees)
{
	t_xyz	ret;
	float	radians;

	radians = to_radians(degrees);
	ret.x = vec.x;
	ret.y = vec.y * cos(radians) - vec.z * sin(radians);
	ret.z = vec.z * cos(radians) + vec.y * sin(radians);
	return (ret);
}
