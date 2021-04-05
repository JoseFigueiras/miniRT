#include "minirt.h"

static t_scene	init_scene(void);
static t_scene	parse_and_fill_scene(t_scene scene, char **words);

t_scene	get_scene(int fd)
{
	char		*temp;
	char		**words;
	t_scene		scene;
	int			i;

	scene = init_scene();
	//printf("scene inited\n");
	while (get_next_line(fd, &temp))
	{
		words = ft_str_split(temp, WHITE_SPACE);
		free(temp);
		if (!words || !*words)		//what am i even doing
			exit(54);
		for (int j = 0; words[j]; j++)
			//printf("%s\n", words[j]);
		//printf("--------\n");
		scene = parse_and_fill_scene(scene, words);
		i = 0;
		while (words[i])
			free(words[i++]);
		free(words);
	}
	return (scene);
}

static t_scene init_scene(void)
{
	t_scene	scene;

	scene.mlx_data = NULL;
	scene.img_data = NULL;
	scene.objlst = NULL;
	scene.amb = NULL;
	scene.camlst = NULL;
	scene.res = NULL;
	return (scene);
}

static t_scene	parse_and_fill_scene(t_scene scene, char **words)
{
	if (ft_strcmp(words[0], "R") == 0)
		scene.res = get_resolution(words);
	else if (!ft_strcmp(words[0], "A"))
		scene.amb = get_ambient_light(words);
	else if (!ft_strcmp(words[0], "c"))
		scene.camlst = camlst_add(words, scene.camlst);
	else if (!ft_strcmp(words[0], "l"))
		scene.lightlst = lightlst_add(words, scene.lightlst);
	else if (!ft_strcmp(words[0], "sp") || !ft_strcmp(words[0], "pl") ||
			!ft_strcmp(words[0], "sq") || !ft_strcmp(words[0], "cy") ||
			!ft_strcmp(words[0], "tr"))
		scene.objlst = objlst_add(words, scene.objlst);
	return (scene);
}
