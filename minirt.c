#include "minirt.h"

int	main(int argc, char **argv)
{
	t_scene	scene;
	int		file_descriptor;
	char	*file_name;

	file_name = get_file_name(argc, argv);
	//printf("file name: %s\n", file_name);
	if (!file_name)
		exit(1);
	file_descriptor = open(file_name, O_RDONLY);
	//printf("fd: %d\n", file_descriptor);
	if (file_descriptor <= 0)
		exit(1);
	//printf("-----get scene-----\n");
	scene = get_scene(file_descriptor);
	//printf("-----got scene-----\n");
	//print_scene(scene);
	if (!is_scene_valid(scene))
		exit(1);
	do_everything(scene);
}
