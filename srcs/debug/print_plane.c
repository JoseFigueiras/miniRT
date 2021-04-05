#include "minirt.h"

void	print_plane(t_plane *plane)
{
	int	color;

	printf("printing plane:\n");
	if (!plane)
	{
		printf("This plane is a NULL ptr\n");
		exit(0);
	}
	printf("coords: x: %f, y: %f, z: %f\n",
			plane->coords.x, plane->coords.y, plane->coords.z);
	printf("vec: x: %f, y: %f, z: %f\n",
			plane->vec.x, plane->vec.y, plane->vec.z);
	color = plane->color;
	printf("color: r: %d, g: %d, b: %d\n", get_r(color), get_g(color), get_b(color));
	printf("\n");
}
