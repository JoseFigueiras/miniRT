#include "minirt.h"

t_triangle	*triangle_new(char **words)
{
	t_triangle	*triangle;

	triangle = malloc(sizeof(t_triangle));
	if (!triangle)
		return (NULL);
	triangle->point1 = get_coords(words[1]);
	triangle->point2 = get_coords(words[2]);
	triangle->point3 = get_coords(words[3]);
	triangle->color = get_rgb(words[4]);
	return (triangle);
}
