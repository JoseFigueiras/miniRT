#include "minirt.h"

t_xyz	get_coords(char *str)
{
	t_xyz	ret;
	char	temp[9];
	int		i;

	ft_memset(temp, '\0', 9);
	i = 0;
	while (i < 9 && (ft_isdigit(str[i]) || str[i] == '-' || str[i] == '.'))
	{
		temp[i] = str[i];
		i++;
	}
	ret.x = atof(temp);
	str += i + 1;
	ft_memset(temp, '\0', 9);
	i = 0;
	while (i < 9 && (ft_isdigit(str[i]) || str[i] == '-' || str[i] == '.'))
	{
		temp[i] = str[i];
		i++;
	}
	ret.y = atof(temp);
	str += i + 1;
	ft_memset(temp, '\0', 9);
	i = 0;
	while (i < 9 && (ft_isdigit(str[i]) || str[i] == '-' || str[i] == '.'))
	{
		temp[i] = str[i];
		i++;
	}
	ret.z = atof(temp);
	return (ret);
}
