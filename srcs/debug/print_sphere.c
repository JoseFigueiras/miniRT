#include "minirt.h"

void	print_sphere(t_sphere *sphere)
{
	int	color;

	printf("printing sphere:\n");
	if (!sphere)
	{
		printf("This sphere is a NULL ptr\n");
		exit(0);
	}
	printf("coords: x: %f, y: %f, z: %f\n",
			sphere->coords.x, sphere->coords.y, sphere->coords.z);
	printf("diameter: %f\n", sphere->diameter);
	color = sphere->color;
	printf("color: r: %d, g: %d, b: %d\n", get_r(color), get_g(color), get_b(color));
	printf("\n");
}
