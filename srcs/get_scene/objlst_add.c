#include "minirt.h"

static t_objlst	*objlst_new(char *word);
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

static t_objlst	*objlst_new(char *word)
{
	t_objlst	*new;

	new = malloc(sizeof(t_objlst));
	if (!new)
		return (NULL);
	new->type = ft_strdup(word);
	if (!new.type)
		return (NULL);
	new.next = NULL;
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
