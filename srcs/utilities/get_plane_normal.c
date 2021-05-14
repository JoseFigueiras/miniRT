#include "minirt.h"

t_xyz	get_plane_normal(t_plane *plane, t_xyz point)
{
	(void)point;
	return (plane->vec);
}
