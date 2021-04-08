#include "minirt.h"

float	points_distance(t_xyz point1, t_xyz point2)
{
	t_xyz	vec;

	vec.x = point1.x - point2.x;
	vec.y = point1.y - point2.y;
	vec.z = point1.z - point2.z;
	return (vec_length(vec));
}
