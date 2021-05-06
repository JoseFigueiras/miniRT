#include "minirt.h"

static t_euler	vec_to_euler(t_xyz vec);
static t_xyz	euler_to_vec(t_euler euler);

t_line	get_line(int x, int y, t_scene scene)
{
	t_line	line;
	float	fov;
	float	x_max;
	float	y_max;
	t_euler	euler;

	fov = (float)scene.camlst->fov;
	x_max = (float)scene.res->x;
	y_max = (float)scene.res->y;

	euler = vec_to_euler(normalize_vec(scene.camlst->vec));

	euler.yaw += fov * (((float)x - (x_max / 2)) / x_max);
	euler.pitch += fov * (((float)y - (y_max / 2)) / x_max);
	euler = normalize_euler(euler);

	line.point = scene.camlst->coords;
	line.vec = euler_to_vec(euler);

	//if (x == 540 && y == 360)
	//{
	//	printf("euler:\nyaw: %f, pitch %f\n", euler.yaw, euler.pitch);
	//	printf("vec: \nx: %f, y: %f, z: %f\n", line.vec.x, line.vec.y, line.vec.z);
	//}
	return (line);
}

static t_euler	vec_to_euler(t_xyz vec)
{
	t_euler	euler;

	euler.yaw = to_degrees(atan2(vec.y, vec.x));
	euler.pitch = -to_degrees(asin(vec.z));
	return (euler);
}

static t_xyz	euler_to_vec(t_euler euler)
{
	t_xyz	vec;
	float	yaw;
	float	pitch;

	yaw = to_radians(euler.yaw);
	pitch = to_radians(euler.pitch);
	vec.x = cos(yaw) * cos(pitch);
	vec.y = sin(yaw) * cos(pitch);
	vec.z = -sin(pitch);
	return (vec);
}
