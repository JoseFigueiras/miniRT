#include "minirt.h"

t_xyz	rotate_y(t_xyz vec, float degrees)
{
	t_xyz	ret;
	float	radians;

	radians = to_radians(degrees);
	ret.x = vec.x * cos(radians) + vec.z * sin(radians);
	ret.y = vec.y;
	ret.z = vec.z * cos(radians) - vec.x * sin(radians);
	return (ret);
}
