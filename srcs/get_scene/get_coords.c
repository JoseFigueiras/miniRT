#include "minirt.h"

static int	poop(char *str, float *coord);

t_xyz	get_coords(char *str)
{
	t_xyz	ret;

	str += poop(str, &ret.x);
	str++;
	str += poop(str, &ret.y);
	str++;
	str += poop(str, &ret.z);
	return (ret);
}

static int	poop(char *str, float *coord)
{	
	char	temp[9];
	int		i;

	ft_memset(temp, '\0', 9);
	i = 0;
	while (i < 9 && (ft_isdigit(str[i]) || str[i] == '-' || str[i] == '.'))
	{
		temp[i] = str[i];
		i++;
	}
	*coord = atof(temp);
	return (i);
}
