#include "minirt.h"

t_amb	*get_ambient_light(char **words)
{
	t_amb	*ret;

	if (!words || !*words)
		return (NULL);
	if (get_arr_size(words) < 2)
		return (NULL);
	ret = malloc(sizeof(t_amb));
	if (!ret)
		return (NULL);
	ret->brightness = get_brightness(words[1]);
	ret->color = get_rgb(words[2]);
	return (ret);
}
