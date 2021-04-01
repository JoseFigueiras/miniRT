#include "minirt.h"

t_plane	*plane_new(char **words)
{
	t_plane	*plane;

	plane = malloc(sizeof(t_plane));
	if (!plane)
		return (NULL);
	plane->coords = get_coords(words[1]);
	plane->vec = get_vec(words[2]);
	plane->color = get_rgb(words[3]);
	return (plane);
}
