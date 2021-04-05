#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct	s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
}				t_mlx;

typedef struct	s_xyz
{
	float		x;
	float		y;
	float		z;
}				t_xyz;

typedef struct			s_lightlst
{
	t_xyz				coords;
	float				brightness;
	int					color;
	struct s_lightlst	*next;
}						t_lightlst;

typedef struct	s_res
{
	int			x;
	int			y;
}				t_res;

typedef struct	s_amb
{
	float		brightness;
	int			color;
}				t_amb;

typedef struct		s_camlst
{
	t_xyz			coords;
	t_xyz			vec;
	float			fov;
	struct s_camlst	*next;
	struct s_camlst	*prev;
}					t_camlst;

typedef struct	s_sphere
{
	t_xyz		coords;
	float		diameter;
	int			color;
}				t_sphere;

typedef struct	s_plane
{
	t_xyz		coords;
	t_xyz		vec;
	int			color;
}				t_plane;

typedef struct	s_square
{
	t_xyz		coords;
	t_xyz		vec;
	float		side;
	int			color;
}				t_square;

typedef struct	s_cylinder
{
	t_xyz		coords;
	t_xyz		vec;
	float		height;
	float		diameter;
	int			color;
}				t_cylinder;

typedef struct	s_triangle
{
	t_xyz		point1;
	t_xyz		point2;
	t_xyz		point3;
	int			color;
}				t_triangle;

typedef struct		s_objlst
{
	char			*type;
	void			*obj;
	struct s_objlst	*next;
}					t_objlst;

typedef struct	s_scene
{
	t_mlx		*mlx_data;
	t_img		*img_data;
	t_res		*res;
	t_amb		*amb;
	t_camlst	*camlst;
	t_lightlst	*lightlst;
	t_objlst	*objlst;
}				t_scene;

#endif
