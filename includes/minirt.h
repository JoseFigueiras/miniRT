#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"
# include "structs.h"

void	do_everything(t_scene scene);
char	*get_file_name(int argc, char **argv);
t_scene	get_scene(int fd);
int		is_scene_valid(t_scene scene);				//TODO

#endif
