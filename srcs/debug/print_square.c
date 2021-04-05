#include "minirt.h"

void	print_square(t_square *square)
{
	int	color;

	printf("printing square:\n");
	if (!square)
	{
		printf("This square is a NULL ptr\n");
		exit(0);
	}
	printf("coords: x: %f, y: %f, z: %f\n",
			square->coords.x, square->coords.y, square->coords.z);
	printf("vec: x: %f, y: %f, z: %f\n",
			square->vec.x, square->vec.y, square->vec.z);
	printf("side: %f\n", square->side);
	color = square->color;
	printf("color: r: %d, g: %d, b: %d\n", get_r(color), get_g(color), get_b(color));
	printf("\n");
}
