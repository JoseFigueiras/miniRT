#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"
# include "structs.h"

# define WHITE_SPACE " \t\n\r\v\f"

char		*get_file_name(int argc, char **argv);

//-----//	get_scene
t_scene		get_scene(int fd);
t_res		*get_resolution(char **words);
t_amb		*get_ambient_light(char **words);
//TODO: handle mallocs better
t_camlst	*camlst_add(char **words, t_camlst *lst);
t_lightlst	*lightlst_add(char **words, t_lightlst *lst);
t_objlst	*objlst_add(char **words, t_objlst *lst);

//TODO: add here all the TODO obj functions

size_t		get_arr_size(char **arr);
int			get_rgb(char *str);
t_xyz		get_coords(char *str);
t_xyz		get_vec(char *str);
float		get_brightness(char *str);
//-----//

int			is_scene_valid(t_scene scene);					//TODO

void		do_everything(t_scene scene);					//TODO

//-----//	utilities
int			create_trgb(int t, int r, int g, int b);
int			get_t(int trgb);
int			get_r(int trgb);
int			get_g(int trgb);
int			get_b(int trgb);
//-----//

#endif
