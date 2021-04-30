#include "minirt.h"

static void	apply_amb_light(t_scene scene, int *color);
static t_line	get_bounce_line(t_objlst *obj, t_line line);

float	raycast(t_line line, t_scene scene, t_objlst *obj, int *color)
{
	int		type;
	float	distance;
	int		color_temp;
	t_line	bounce_line;

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
//	bounce_line = get_bounce_line(obj, line);
//	if ((*scene.depth)-- > 0)
//	{
//		color_temp = raycast_objs(bounce_line, scene);
//		*color = (*color * 9 / 10) + (color_temp * 1 / 10);
//	}
	//TODO: amb light considers bounc_line angle
	apply_amb_light(scene, color);
	//apply_lightlst();
	return (distance);
}

//static t_line	get_bounce_line(t_objlst *obj, t_line line)
//{
//	t_xyz	normal;
//	float	perp;
//	t_line	bounce;
//
////    const Vector& normal = intersection.surfaceNormal;
////    const double perp = 2.0 * DotProduct(incidentDir, normal);
////    const Vector reflectDir = incidentDir - (perp * normal);
//
//	bounce.point = get_intersection_point(obj, line);
//	//intersection point = vec + distance
//	//distance = raycast()
//	normal = get_normal(obj, bounce.point);
//	perp = 2.0 * dot(line.vec, normal);
//	bounce.vec = vec_sub(line.vec - vec_scale(normal, perp));
//	return (bounce);
//}

//static t_xyz	get_normal(t_objlst *obj, t_xyz point)
//{
//	if ()
//}

static void	apply_amb_light(t_scene scene, int *color)
{
	int		r;
	int		g;
	int		b;
	t_amb	amb;
	float	dot;

	//dot = vec_dot(vec, bounce);
	//dot = (dot + 1) / 2;		//shift range from [-1, 1] to [0, 1]
	amb = *(scene.amb);
	r = amb.brightness * (get_r(amb.color) * 3 / 10) + (get_r(*color) * 7 / 10);
	//r *= dot;
	g = amb.brightness * (get_g(amb.color) * 3 / 10) + (get_g(*color) * 7 / 10);
	//g *= dot;
	b = amb.brightness * (get_b(amb.color) * 3 / 10) + (get_b(*color) * 7 / 10);
	//b *= dot;
	*color = create_trgb(0, r, g, b);
}
