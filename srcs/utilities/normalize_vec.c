#include "minirt.h"

t_xyz	normalize_vec(t_xyz vec)
{
	float	length;

	length = vec_length(vec);
	vec.x /= length;
	vec.y /= length;
	vec.z /= length;
	return (vec);
}
