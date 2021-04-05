#include "minirt.h"

void	print_cylinder(t_cylinder *cylinder)
{
	int	color;

	printf("printing cylinder:\n");
	if (!cylinder)
	{
		printf("This cylinder is a NULL ptr\n");
		exit(0);
	}
	printf("coords: x: %f, y: %f, z: %f\n",
			cylinder->coords.x, cylinder->coords.y, cylinder->coords.z);
	printf("vec: x: %f, y: %f, z: %f\n",
			cylinder->vec.x, cylinder->vec.y, cylinder->vec.z);
	printf("height: %f\n", cylinder->height);
	printf("diameter: %f\n", cylinder->diameter);
	color = cylinder->color;
	printf("color: r: %d, g: %d, b: %d\n", get_r(color), get_g(color), get_b(color));
	printf("\n");
}
