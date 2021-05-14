#include "minirt.h"

static float	sphere_equation_det(t_sphere *sphere, t_line line, float *a,
					float *b);

float	raycast_sphere(t_line line, t_scene scene,
							t_sphere *sphere, int *color)
{
	float		res;
	float		a;
	float		b;
	float		c;
	float		det;

	(void)scene;
	c = sphere_equation_det(sphere, line, &a, &b);
	det = b * b - 4 * a * c;
	if (det >= 0)
	{
		det = sqrt(det);
		res = positive_smallest((-b + det) / (2 * a),
				(-b - det) / (2 * a));
		*color = sphere->color;
		return (res);
	}
	return (HUGE_VAL);
}

static float	sphere_equation_det(t_sphere *sphere, t_line line,
					float *a, float *b)
{
	t_xyz		ray_direction;
	t_xyz		ray_origin;
	t_xyz		s_origin;
	float		radius;
	float		c;

	ray_direction = line.vec;
	ray_origin = line.point;
	s_origin = sphere->coords;
	radius = sphere->diameter / 2;
	*a = ray_direction.x * ray_direction.x + ray_direction.y
		* ray_direction.y + ray_direction.z * ray_direction.z;
	*b = 2 * (ray_direction.x * (ray_origin.x - s_origin.x)
			+ ray_direction.y * (ray_origin.y - s_origin.y)
			+ ray_direction.z * (ray_origin.z - s_origin.z));
	c = (ray_origin.x - s_origin.x) * (ray_origin.x - s_origin.x)
		+ (ray_origin.y - s_origin.y)
		* (ray_origin.y - s_origin.y)
		+ (ray_origin.z - s_origin.z)
		* (ray_origin.z - s_origin.z) - radius * radius;
	return (c);
}
