#include "minirt.h"

static t_lightlst	*lightlst_new(t_xyz coords, float brightness, int color);
static t_lightlst	*lightlst_push(t_lightlst *lst, t_lightlst *new);

t_lightlst	*lightlst_add(char **words, t_lightlst *lst)
{
	t_lightlst	*new;
	t_xyz		coords;
	float		brightness;
	int			color;

	coords = get_coords(words[1]);
	brightness = atof(words[2]);
	color = get_rgb(words[3]);
	new = lightlst_new(coords, brightness, color);
	if (!lst)
		lst = new;
	else
		lst = lightlst_push(lst, new);
	return (lst);
}

static t_lightlst	*lightlst_new(t_xyz coords, float brightness, int color)
{
	t_lightlst	*new;

	new = malloc(sizeof(t_lightlst));
	if (!new)
		return (NULL);
	new->coords = coords;
	new->brightness = brightness;
	new->color = color;
	new->next = NULL;
	return (new);
}

static t_lightlst	*lightlst_push(t_lightlst *lst, t_lightlst *new)
{
	t_lightlst	*current;

	current = lst;
	while (current->next)
		current = current->next;
	current->next = new;
	return (lst);
}
