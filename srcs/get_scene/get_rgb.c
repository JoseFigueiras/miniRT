#include "minirt.h"

int	get_rgb(char *str)
{
	char	temp[4];
	int		r;
	int		g;
	int		b;
	int		i;

	ft_memset(temp, '\0', 4);
	i = 0;
	while (i < 4 && ft_isdigit(str[i]))
	{
		temp[i] = str[i];
		i++;
	}
	r = ft_atoi(temp);
	str += i + 1;
	ft_memset(temp, '\0', 4);
	i = 0;
	while (i < 4 && ft_isdigit(str[i]))
	{
		temp[i] = str[i];
		i++;
	}
	g = ft_atoi(temp);
	str += i + 1;
	ft_memset(temp, '\0', 4);
	i = 0;
	while (i < 4 && ft_isdigit(str[i]))
	{
		temp[i] = str[i];
		i++;
	}
	b = ft_atoi(temp);
	return(create_trgb(0, r, g, b));
}
