#include "minirt.h"

t_cylinder	*cylinder_new(char **words)
{
	t_cylinder	*cylinder;

	cylinder = malloc(sizeof(t_cylinder));
	if (!cylinder)
		return (NULL);
	cylinder->coords = get_coords(words[1]);
	cylinder->vec = get_vec(words[2]);
	cylinder->height = atof(words[3]);
	cylinder->diameter = atof(words[4]);
	cylinder->color = get_rgb(words[5]);
	return (cylinder);
}
