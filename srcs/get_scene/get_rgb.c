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
		temp[i] = str[i++];
	r = ft_clamp(0, ft_atoi(temp), 255);
	str += i + 1;
	ft_memset(temp, '\0', 4);
	i = 0;
	while (i < 4 && ft_isdigit(str[i]))
		temp[i] = str[i++];
	g = ft_clamp(0, ft_atoi(temp), 255);
	str += i + 1;
	ft_memset(temp, '\0', 4);
	i = 0;
	while (i < 4 && ft_isdigit(str[i]))
		temp[i] = str[i++];
	b = ft_clamp(0, ft_atoi(temp), 255);
	return(create_trgb(0, r, g, b));
}
