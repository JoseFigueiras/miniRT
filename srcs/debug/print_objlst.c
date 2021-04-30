#include "minirt.h"

void	print_objlst(t_objlst *objlst)
{
	t_objlst	*current;

	current = objlst;
	while (current)
	{
		if (current->type == SPHERE)
			print_sphere(current->obj);
		else if (current->type == PLANE)
			print_plane(current->obj);
		else if (current->type == SQUARE)
			print_square(current->obj);
		else if (current->type == CYLINDER)
			print_cylinder(current->obj);
		else if (current->type == TRIANGLE)
			print_triangle(current->obj);
		current = current->next;
	}
	printf("Finished printing objlst\n");
}
