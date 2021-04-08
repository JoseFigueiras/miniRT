#include "minirt.h"

t_xyz	rotate_z(t_xyz vec, float degrees)
{
	t_xyz	ret;
	float	radians;

	radians = to_radians(degrees);
	ret.x = vec.x * cos(radians) - vec.y * sin(radians);
	ret.y = vec.y * cos(radians) + vec.x * sin(radians);
	ret.z = vec.z;
	return (ret);
}
