#include "minirt.h"

char	*get_file_name(int argc, char **argv)
{
	char	*ret;

	if (argc <= 1)
		return (NULL);
	ret = ft_strdup(argv[1]);
	return (ret);
}
