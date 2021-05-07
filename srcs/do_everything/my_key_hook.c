#include "minirt.h"

int	my_key_hook(int keycode, t_scene *scene)
{
	if (keycode == LEFT_ARROW)
		scene->camlst = scene->camlst->prev;
	else if (keycode == RIGHT_ARROW)
		scene->camlst = scene->camlst->next;
	else if (keycode == ESC)
		exit(0);
	return (1);
}

