#include "minirt.h"

void	print_objlst(t_objlst *objlst)
{
	t_objlst	*current;

	current = objlst;
	while (current)
	{
		if (!ft_strcmp(current->type, "sp"))
			print_sphere(current->obj);
		else if (!ft_strcmp(current->type, "pl"))
			print_plane(current->obj);
		else if (!ft_strcmp(current->type, "sq"))
			print_square(current->obj);
		else if (!ft_strcmp(current->type, "cy"))
			print_cylinder(current->obj);
		else if (!ft_strcmp(current->type, "tr"))
			print_triangle(current->obj);
		current = current->next;
	}
	printf("Finished printing objlst\n");
}
