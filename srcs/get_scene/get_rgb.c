#include "minirt.h"

static int	poop(char *str, int *i);

int	get_rgb(char *str)
{
	int		r;
	int		g;
	int		b;

	str += poop(str, &r);
	str++;
	str += poop(str, &g);
	str++;
	str += poop(str, &b);
	return (create_trgb(0, r, g, b));
}

static int	poop(char *str, int *color)
{
	int		i;
	char	temp[9];

	ft_memset(temp, '\0', 9);
	i = 0;
	while (i < 9 && ft_isdigit(str[i]))
	{
		temp[i] = str[i];
		i++;
	}
	*color = ft_atoi(temp);
	return (i);
}
