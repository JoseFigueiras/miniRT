#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "mlx.h"
# include "../Libft/libft.h"
# include "structs.h"

# define WHITE_SPACE " \t\n\r\v\f"

//DEBUG//
void		print_scene(t_scene scene);
void		print_objlst(t_objlst *objlst);		//TODO
//DEBUG//

char		*get_file_name(int argc, char **argv);

//-----//	get_scene
t_scene		get_scene(int fd);
t_res		*get_resolution(char **words);
t_amb		*get_ambient_light(char **words);
//TODO: handle mallocs better (perhaps?)
t_camlst	*camlst_add(char **words, t_camlst *lst);
t_lightlst	*lightlst_add(char **words, t_lightlst *lst);
t_objlst	*objlst_add(char **words, t_objlst *lst);
//-//
t_sphere	*sphere_new(char **words);
t_plane		*plane_new(char **words);
t_square	*square_new(char **words);
t_cylinder	*cylinder_new(char **words);
t_triangle	*triangle_new(char **words);
//-//
size_t		get_arr_size(char **arr);
int			get_rgb(char *str);
t_xyz		get_coords(char *str);
t_xyz		get_vec(char *str);
float		get_brightness(char *str);
//-----//	get_scene end

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
