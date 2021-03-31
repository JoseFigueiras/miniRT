#include "minirt.h"

size_t	get_arr_size(char **arr)
{
	size_t	count;

	count = 0;
	if (!arr)
		return(0);
	while (*arr++)
		count++;
	return (count);
}
