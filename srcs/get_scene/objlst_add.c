#include "minirt.h"

static t_objlst	*objlst_new(char *type);
static t_objlst	*objlst_push(t_objlst *lst, t_objlst *new);

t_objlst	*objlst_add(char **words, t_objlst *lst)
{
	t_objlst	*new;
	void		*obj;

	new = objlst_new(words[0]);
	//handle this malloc
	if (!ft_strcmp(words[0], "sp"))
		obj = sphere_new(words);
	else if (!ft_strcmp(words[0], "pl"))
		obj = plane_new(words);
	else if (!ft_strcmp(words[0], "sq"))
		obj = square_new(words);
	else if (!ft_strcmp(words[0], "cy"))
		obj = cylinder_new(words);
	else if (!ft_strcmp(words[0], "tr"))
		obj = triangle_new(words);
	new->obj = obj;
	if (!lst)
		lst = new;
	else
		lst = objlst_push(lst, new);
	return (lst);
}

static t_objlst	*objlst_new(char *type)
{
	t_objlst	*new;

	new = malloc(sizeof(t_objlst));
	if (!new)
		return (NULL);
	if (!ft_strcmp(type, "sp"))
		new->type = SPHERE;
	else if (!ft_strcmp(type, "pl"))
		new->type = PLANE;
	else if (!ft_strcmp(type, "sq"))
		new->type = SQUARE;
	else if (!ft_strcmp(type, "cy"))
		new->type = CYLINDER;
	else if (!ft_strcmp(type, "tr"))
		new->type = TRIANGLE;
	else
		printf("Uh oh, spaghetti-oh's!\n");
	new->next = NULL;
	return (new);
}

static t_objlst	*objlst_push(t_objlst *lst, t_objlst *new)
{
	t_objlst	*current;

	current = lst;
	while (current->next)
		current = current->next;
	current->next = new;
	return (lst);
}
