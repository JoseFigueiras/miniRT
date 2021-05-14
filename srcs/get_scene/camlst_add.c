#include "minirt.h"

static t_camlst	*camlst_new(t_xyz coords, t_xyz vec, float fov);
static t_camlst	*camlst_insert(t_camlst *lst, t_camlst *new);

t_camlst	*camlst_add(char **words, t_camlst *lst)
{
	t_camlst	*new;
	t_xyz		coords;
	t_xyz		vec;
	float		fov;

	coords = get_coords(words[1]);
	vec = get_vec(words[2]);
	fov = atof(words[3]);
	new = camlst_new(coords, vec, fov);
	if (!lst)
	{
		lst = new;
		lst->next = lst;
		lst->prev = lst;
	}
	else
		lst = camlst_insert(lst, new);
	return (lst);
}

static t_camlst	*camlst_new(t_xyz coords, t_xyz vec, float fov)
{
	t_camlst	*new;

	new = malloc(sizeof(t_camlst));
	if (!new)
		return (NULL);
	new->coords = coords;
	new->vec = vec;
	new->fov = fov;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

static t_camlst	*camlst_insert(t_camlst *lst, t_camlst *new)
{
	lst->prev->next = new;
	new->prev = lst->prev;
	lst->prev = new;
	new->next = lst;
	return (lst);
}
