#include "minirt.h"

t_xyz	get_coords(char *str)
{
	t_xyz	ret;
	char	temp[4];

	ft_memset(temp, '\0', 4);
	i = 0;
	while (i < 4 && ft_isdigit(str[i]))
		temp[i] = str[i++];
	ret.x = atof(temp);
	str += i + 1;
	ft_memset(temp, '\0', 4);
	i = 0;
	while (i < 4 && ft_isdigit(str[i]))
		temp[i] = str[i++];
	ret.y = atof(temp);
	str += i + 1;
	ft_memset(temp, '\0', 4);
	i = 0;
	while (i < 4 && ft_isdigit(str[i]))
		temp[i] = str[i++];
	ret.z = atof(temp);
	return (ret);
}
