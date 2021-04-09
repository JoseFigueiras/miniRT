#include "minirt.h"

static t_line	get_new_line(int x, int y, t_scene scene);

t_line	get_line(int x, int y, t_scene scene)
{
	t_line	cam_line;
	t_line	new_line;
	t_line	ret_line;

	cam_line.point = scene.camlst->coords;
	cam_line.vec = scene.camlst->vec;

	new_line = get_new_line(x, y, scene);

	ret_line.point = vec_add(cam_line.point, new_line.point);
	ret_line.vec = new_line.vec;
	return (ret_line);
}

static t_line	get_new_line(int x, int y, t_scene scene)
{
	t_line		line;
	t_camlst	cam;
	t_res		res;
	float		yaw;
	float		pitch;

	cam = *scene.camlst;
	res = *scene.res;
	line.point.x = 0;
	line.point.y = 0;
	line.point.z = -1 / (tan(cam.fov / 2));
	line.vec.x = x - ((float)res.x / 2);
	line.vec.y = y - ((float)res.x / 2);
	line.vec.z = 1 / tan(cam.fov / 2);
	yaw = cam.fov;
	pitch = (cam.fov * res.y) / res.x;
	line.vec = rotate_x(line.vec, pitch);
	line.vec = rotate_y(line.vec, yaw);
	return (line);
}

//t_line	get_line(int x, int y, t_scene scene)
//{
//	t_line	line;
//	float	fov;
//	float	x_max;
//	float	y_max;
//	float	angle;
//
//	fov = (float)scene.camlst->fov;
//	x_max = (float)scene.res->x;
//	y_max = (float)scene.res->y;
//	line.point = scene.camlst->coords;
//	line.vec = scene.camlst->vec;
//	angle = ((y - (y_max / 2)) * (fov / 2)) / (y_max / 2);
//	line.vec = rotate_z(line.vec, angle);
//	return (line);
//}
