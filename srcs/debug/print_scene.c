#include "minirt.h"

static void	print_res(t_res *res);
static void	print_amb(t_amb *amb);
static void	print_camlst(t_camlst *camlst);
static void	print_lightlst(t_lightlst *lightlst);

void	print_scene(t_scene scene)
{
	printf("\n//-----//Printing Scene//-----//\n\n");
	printf("\n// Printing Res //\n\n");
	print_res(scene.res);
	printf("\n// Printing Amb //\n\n");
	print_amb(scene.amb);
	printf("\n// Printing Cams //\n\n");
	print_camlst(scene.camlst);
	printf("\n// Printing Lights //\n\n");
	print_lightlst(scene.lightlst);
	printf("\n// Printing Objs //\n\n");
	print_objlst(scene.objlst);
	printf("\n//-----//Finished printing//-----//\n\n");
}

static void	print_res(t_res *res)
{
	if (!res)
	{
		printf("Error: res is a NULL ptr\n");
		return ;
	}
	printf("int x: %d\n", res->x);
	printf("int y: %d\n", res->y);
}

static void	print_amb(t_amb *amb)
{
	int	color;

	if (!amb)
	{
		printf("Error: amb is a NULL ptr\n");
		return ;
	}
	color = amb->color;
	printf("float brightness: %f\n", amb->brightness);
	printf("color: r: %d, g: %d, b: %d\n",
		get_r(color), get_g(color), get_b(color));
}

static void	print_camlst(t_camlst *camlst)
{
	t_camlst	*save;
	t_camlst	*current;

	if (!camlst)
	{
		printf("Error: camlst is a NULL ptr\n");
		return ;
	}
	save = camlst;
	current = camlst;
	do
	{
		printf(" start node\n");
		printf("coords: x: %f, y: %f, z: %f\n",
			current->coords.x, current->coords.y, current->coords.z);
		printf("vec: x: %f, y: %f, z: %f\n",
			current->vec.x, current->vec.y, current->vec.z);
		printf("float fov: %f\n", current->fov);
		printf(" end node\n");
		current = current->next;
	} while (current != save);
}

static void	print_lightlst(t_lightlst *lightlst)
{
	t_lightlst	*current;
	int			color;

	if (!lightlst)
	{
		printf("Error: lightlst is a NULL ptr\n");
		return ;
	}
	current = lightlst;
	while (current)
	{
		color = current->color;
		printf("start node\n");
		printf("coords: x: %f, y: %f, z: %f\n", current->coords.x,
			current->coords.y, current->coords.z);
		printf("float brightness: %f\n", current->brightness);
		printf("color: r: %d, g: %d, b: %d\n",
			get_r(color), get_g(color), get_b(color));
		printf("end node\n");
		current = current->next;
	}
}
