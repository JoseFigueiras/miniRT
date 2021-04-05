#include "minirt.h"

void	print_triangle(t_triangle *triangle)
{
	int	color;

	printf("printing triangle:\n");
	if (!triangle)
	{
		printf("This triangle is a NULL ptr\n");
		exit(0);
	}
	printf("point1: x: %f, y: %f, z: %f\n",
			triangle->point1.x, triangle->point1.y, triangle->point1.z);
	printf("point2: x: %f, y: %f, z: %f\n",
			triangle->point2.x, triangle->point2.y, triangle->point2.z);
	printf("point3: x: %f, y: %f, z: %f\n",
			triangle->point3.x, triangle->point3.y, triangle->point3.z);
	color = triangle->color;
	printf("color: r: %d, g: %d, b: %d\n", get_r(color), get_g(color), get_b(color));
	printf("\n");
}
