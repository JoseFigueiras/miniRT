#include "minirt.h"

t_res	*get_resolution(char **words)
{
	t_res	*ret;

	if (!words || !*words)
		return (NULL);
	if (get_arr_size(words) < 3)
		return (NULL);
	ret = malloc(sizeof(t_res));
	if (!ret)
		return (NULL);
	ret.x = ft_atoi(words[1]);
	ret.y = ft_atoi(words[2]);
	return (ret);
}
