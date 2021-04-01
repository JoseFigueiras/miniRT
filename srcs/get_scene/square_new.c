#include "minirt.h"

t_square	*square_new(char **words)
{
	t_square	*square;

	square = malloc(sizeof(t_square));
	if (!square)
		return (NULL);
	square->coords = get_coords(words[1]);
	square->vec = get_vec(words[2]);
	square->side = atof(words[3]);
	square->color = get_rgb(words[4]);
	return (square);
}
