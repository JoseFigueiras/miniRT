#include "minirt.h"

static int	in_height_range(t_cylinder *cylinder, t_line line, float distance);

float		raycast_cylinder(t_line line, t_scene scene,
							t_cylinder *cylinder, int *color)
{
	float	a;
	float	b;
	float	c;
	float	det;
	float	distance;

	(void)scene;
	a = line.vec.x * line.vec.x + line.vec.y * line.vec.y;
	b = 2 * (line.point.x * line.vec.x + line.point.y * line.vec.y
		- line.vec.x * cylinder->coords.x - line.vec.y * cylinder->coords.y);
	c = line.point.x * line.point.x + line.point.y * line.point.y +
		cylinder->coords.x * cylinder->coords.x + 
		cylinder->coords.y * cylinder->coords.y - 
		(cylinder->diameter / 2) * (cylinder->diameter / 2) - 2 *
		(line.point.x * cylinder->coords.x +
		line.point.y * cylinder->coords.y);
	det = b * b - 4 * a * c;
	if (det >= MIN_THRESHOLD)
	{
		det = sqrt(det);
		distance = positive_smallest((-b + det) / (2 * a),
										(-b - det) / (2 * a));
		if (in_height_range(cylinder, line, distance))
		{
			*color = cylinder->color;
			return (distance);
		}
	}
	return (HUGE_VAL);
}

static int	in_height_range(t_cylinder *cylinder, t_line line, float distance)
{
	t_xyz	intersect;
	int		is_high;
	int		is_low;

	is_high = 0;
	is_low = 0;
	intersect = vec_add(line.point, vec_scale(line.vec, distance));
	if (intersect.z > cylinder->coords.z + cylinder->height / 2)
		is_high = 1;
	if (intersect.z < cylinder->coords.z - cylinder->height / 2)
		is_low = 1;
	if (is_low || is_high)
		return (0);
	return (1);
}
