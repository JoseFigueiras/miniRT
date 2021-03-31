#include "minirt.h"

t_xyz	get_xyz(char *str)
{
	t_xyz	ret;
	char	temp[4];

	ft_memset(temp, '\0', 4);
	i = 0;
	while (i < 4 && ft_isdigit(str[i]))
		temp[i] = str[i++];
	ret.x = ft_fclamp(-1, atof(temp), 1);
	str += i + 1;
	ft_memset(temp, '\0', 4);
	i = 0;
	while (i < 4 && ft_isdigit(str[i]))
		temp[i] = str[i++];
	ret.y = ft_fclamp(-1, atof(temp), 1);
	str += i + 1;
	ft_memset(temp, '\0', 4);
	i = 0;
	while (i < 4 && ft_isdigit(str[i]))
		temp[i] = str[i++];
	ret.z = ft_fclamp(-1, atof(temp), 1);
	return (ret);
}
