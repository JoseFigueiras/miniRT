#include "minirt.h"

float	raycast(t_line line, t_scene scene, t_objlst *obj, int *color)
{
	int		type;
	float	distance;

	//printf("vec: \nx: %f, y: %f, z: %f\n", line.vec.x, line.vec.y, line.vec.z);
	distance = HUGE_VAL;
	type = obj->type;
	if (type == SPHERE)
		distance = raycast_sphere(line, scene, obj->obj, color);
	else if (type == PLANE)
		distance = raycast_plane(line, scene, obj->obj, color);
	else if (type == SQUARE)
		distance = raycast_square(line, scene, obj->obj, color);
	else if (type == CYLINDER)
		distance = raycast_cylinder(line, scene, obj->obj, color);
	else if (type == TRIANGLE)
		distance = raycast_triangle(line, scene, obj->obj, color);
	if (distance <= MIN_THRESHOLD)
		distance = HUGE_VAL;
	return (distance);
}
