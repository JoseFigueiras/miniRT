#include "minirt.h"

t_xyz	vec_scale(t_xyz vec, float scalar)
{
	t_xyz	ret;

	ret.x = vec.x * scalar;
	ret.y = vec.y * scalar;
	ret.z = vec.z * scalar;
	return (ret);
}
