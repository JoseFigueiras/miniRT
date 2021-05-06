#include "minirt.h"

t_line	get_bounce_line(t_objlst *obj, t_line line, float distance)
{
	t_xyz	normal;
	float	perp;
	t_line	bounce;

//    const Vector& normal = intersection.surfaceNormal;
//    const double perp = 2.0 * DotProduct(incidentDir, normal);
//    const Vector reflectDir = incidentDir - (perp * normal);

	bounce.point = vec_add(line.point, vec_scale(line.vec, distance));
	normal = get_normal(obj, bounce.point);
	perp = 2.0 * dot(line.vec, normal);
	bounce.vec = vec_sub(line.vec, vec_scale(normal, perp));
	bounce.vec = normalize_vec(bounce.vec);
	return (bounce);
}
