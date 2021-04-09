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

char		*get_file_name(int argc, char **argv);

//-----//	get_scene				//------------------------------//
t_scene		get_scene(int fd);
t_res		*get_resolution(char **words);
t_amb		*get_ambient_light(char **words);
//TODO: handle mallocs better (perhaps?)
t_camlst	*camlst_add(char **words, t_camlst *lst);
t_lightlst	*lightlst_add(char **words, t_lightlst *lst);
t_objlst	*objlst_add(char **words, t_objlst *lst);
	t_sphere	*sphere_new(char **words);
	t_plane		*plane_new(char **words);
	t_square	*square_new(char **words);
	t_cylinder	*cylinder_new(char **words);
	t_triangle	*triangle_new(char **words);
size_t		get_arr_size(char **arr);
int			get_rgb(char *str);
t_xyz		get_coords(char *str);
t_xyz		get_vec(char *str);
float		get_brightness(char *str);
//-----//	get_scene end			//------------------------------//

int			is_scene_valid(t_scene scene);					//TODO

//-----//	do_everything			//------------------------------//
void		do_everything(t_scene scene);
int			get_pixel_color(int x, int y, t_scene scene);
t_line		get_line(int x, int y, t_scene scene);			//TODO
int			raycast_objs(t_line line, t_scene scene);
float		raycast(t_line line, t_scene scene, t_objlst *obj, int *color);

float		raycast_sphere(t_line line, t_scene scene,		//TODO
							t_sphere *obj, int *color);
float		raycast_plane(t_line line, t_scene scene,		//TODO
							t_plane *obj, int *color);
float		raycast_square(t_line line, t_scene scene,		//TODO
							t_square *obj, int *color);
float		raycast_cylinder(t_line line, t_scene scene,	//TODO
							t_cylinder *obj, int *color);
float		raycast_triangle(t_line line, t_scene scene,	//TODO
							t_triangle *obj, int *color);

//-----//	do_everything end		//------------------------------//

//-----//	utilities				//------------------------------//
int			create_trgb(int t, int r, int g, int b);
int			get_t(int trgb);
int			get_r(int trgb);
int			get_g(int trgb);
int			get_b(int trgb);

void		my_mlx_pixel_put(t_img *img, int x, int y, int color);

float		vec_length(t_xyz vec);
float		points_distance(t_xyz point1, t_xyz point2);
t_xyz		normalize_vec(t_xyz vec);
float		dot(t_xyz v1, t_xyz v2);
t_xyz		vec_sub(t_xyz v1, t_xyz v2);
t_xyz		vec_add(t_xyz v1, t_xyz v2);
t_xyz		vec_scale(t_xyz vec, float scalar);
float		to_radians(float degrees);
t_xyz		rotate_x(t_xyz vec, float degrees);
t_xyz		rotate_y(t_xyz vec, float degrees);
t_xyz		rotate_z(t_xyz vec, float degrees);

//-----//							//------------------------------//

//DEBUG//
void		print_scene(t_scene scene);
void		print_objlst(t_objlst *objlst);
	void		print_sphere(t_sphere *sphere);
	void		print_plane(t_plane *plane);
	void		print_square(t_square *square);
	void		print_cylinder(t_cylinder *cylinder);
	void		print_triangle(t_triangle *triangle);
//DEBUG//

#endif
