#include "minirt.h"

int	raycast_objs(t_line line, t_scene scene)
{
	t_objlst	*current;
	int			color;
	int			color_temp;
	float		distance;
	float		distance_temp;

	color = 0;
	color_temp = 0;
	distance = 0;
	distance_temp = 0;
	current = scene.objlst;
	while (current)
	{
		distance_temp = raycast(line, scene, current, &color_temp);
		if (distance_temp <= distance)
		{
			color = color_temp;
			distance = distance_temp;
		}
		current = current->next;
	}
	return (color);
}