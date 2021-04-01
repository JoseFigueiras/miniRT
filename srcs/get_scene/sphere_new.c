#include "minirt.h"

t_sphere	*sphere_new(char **words)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		return (NULL);
	sphere->coords = get_coords(words[1]);
	sphere->diameter = atof(words[2]);
	sphere->color = get_rgb(words[3]);
	return (sphere);
}
