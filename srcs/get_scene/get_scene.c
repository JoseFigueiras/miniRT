#include "minirt.h"

static t_scene	init_scene(void);
static t_scene	parse_and_fill_scene(t_scene scene, char **words);

t_scene	get_scene(int fd)
{
	char		*temp;
	char		**words;
	t_scene		scene;

	scene = init_scene();
	while (get_next_line(fd, &temp))
	{
		words = ft_str_split(temp, WHITE_SPACE);
		free(temp);
		if (!words || !*words)		//what am i even doing
			exit(54);
		scene = parse_and_fill_scene(scene, words);
		while (*words)
			free(*words++);
		free(words);
	}
	return (scene);
}

static t_scene init_scene(void)
{
	t_scene	scene;

	scene.mlx_data.mlx = NULL;
	scene.mlx_data.win = NULL;
	scene.objlst = NULL;
	scene.amb = NULL;
	scene.camlst = NULL;
	x = 0;
	y = 0;
	return (scene);
}

static t_scene	parse_and_fill_scene(t_scene scene, char **words)
{
	if (!ft_strcmp(words[0], "R"))
		scene.res = get_resolution(words);
	else if (!ft_strcmp(words[0], "A"))
		scene.amb = get_ambient_light(words);
	else if (!ft_strcmp(words[0], "c"))
		scene.camlst = camlst_add(words, &scene.camlst);
	else if (!ft_strcmp(words[0], "l"))
		scene.lightlst = lightlst_add(words, &scene.lightlst);
	else if (!ft_strcmp(words[0], "sp" || !ft_strcmp(words[0], "pl" ||
			!ft_strcmp(words[0], "sq" || !ft_strcmp(words[0], "cy" ||
			!ft_strcmp(words[0], "tr"))
		scene.objlst = objlst_add(words, &scene.objlst);
	return (scene);
}
