/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 16:59:17 by iradchen          #+#    #+#             */
/*   Updated: 2018/02/23 19:47:28 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <math.h>
# include "mlx.h"
# include "libft.h"
# include <fcntl.h>
# define DBL_MAX 2147483647
# define WIDTH 600
# define HEIGHT 600
# define INT_ARR_SIZE (sizeof(int) * 3)
# define DOUB_ARR_SIZE (sizeof(double) * 3)
# define AMBIENT 0
# define POINT 1
# define DIRECTIONAL 2
# define SQUARE(x) (x * x)
# define NOSPECULAR -1
# define DEGREE 0.0174532925
# define ABS(x) (x > 0 ? x : -x)

typedef struct s_inter		t_inter;

typedef struct	s_object
{
	double 	refl;
	double	r;
	int		color;
	int		specular;
	double	sq_cos;
	double	sq_sin;
	double	*c;
	double	*dir;
	void	(*inter_cof)(double *, t_inter *, double *, struct s_object *);
	double	*(*compute_normal)(struct s_object *, double *);
}				t_object;

struct			s_inter
{
	double		closest_t;
	t_object	*closest_object;
	double		*point_on_object;
	double		*ray_dir;
	double		from;
	double		to;
};

typedef struct	s_cam
{
	double		*origin;
	double		**rotate_matrix;
}				t_cam;

typedef struct	s_scene
{
	char		*name;
	int			shadow;
	t_list		*lightes;
	t_list		*objects;
	t_cam		*cam;
}				t_scene;

typedef struct	s_img
{
	void	*ptr;
	int		*data;
	int		size;
}				t_img;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_scene	*scene;
	t_img	*img;
}				t_mlx;

typedef struct	s_light
{
	int		type;
	double	intensity;
	double	*info;
}				t_light;

typedef struct	s_light_st
{
	double	*point_on_object;
	double	*from_point_to_cam;
	double	*object_normal;
	double	refl_intens;
	double	color_intens;
	double	len_from_point_to_cam;
	int		object_specular;
	int		color;
}				t_light_st;

void			init_scene(t_scene *scene);
void			init_objects(char **info, t_list **objects, int inf_len);
void			init_cam(char **info, t_cam **cam);
void			init_lights(char **info, t_list **lights, int inf_len);

void			del_cam(t_cam **cam);

void			change_params(double t, t_object *object, t_inter *inter);
double			*get_double_arr(char *str);
int				*get_int_arr(char *str);
double			ft_atod(char *str);

void			set_sphere(char **info, t_object *object);
void			set_cone(char **info, t_object *object);
void			set_plane(char **info, t_object *object);
void			set_cylinder(char **info, t_object *object);

void			draw(t_mlx *mlx);

double			dot(double *v, double *w);
double			dot_2(double *v, double *w);
double			*sub(double *v, double *w);
double			*add(double *v, double *w);
double			*mult_on_sc(double *v, double sc);
double			*add_sc(double *v, double *w, double scale);
double			*get_zero_vec(void);
double			*cross(double *u, double *v);

void			rotate(double *point, double **matrix);
void			del_matrix(double ***matrix);
double			**mult_matrix(double **matrix1, double **matrix2);
double			**get_zero_matrix(void);
double			**get_rotate_x(double angle);
double			**get_rotate_y(double angle);
double			**get_rotate_z(double angle);
double			**trans_matrix(double **matrix);
double			**get_rotate_matrix(char *info);

int				trace_ray(double *ray_dir, double *start_point, t_scene *scene, \
								double ray_start, double ray_end, int recursion_depth);

void			compute_light(t_light_st *lightstate, t_scene *scene);
double			*refl_ray(double *object_normal, double *light_vector,\
double normal_dot_light_vector);
int				add_two_color(int color1, int color2);

double			len(double *v);

int				compute_color(t_light_st *light_st, t_scene *scene);
int				to_rgb(int color, double lighting);

void			closest_inter(double *from_p, t_inter *inter, t_scene *scene);
void			inter_sphere(double *cof, t_inter *inter, \
	double *cam, t_object *object);
void			inter_cylinder(double *cof, t_inter *inter, \
	double *cam, t_object *object);
void			inter_plane(double *cof, t_inter *inter, \
	double *cam, t_object *object);
void			inter_cone(double *cof, t_inter *inter, \
	double *cam, t_object *object);
void			inter_ray_object(t_inter *inter, double *inter_points, \
	double *from_point, t_object *object);

double			*cylinder_normal(t_object *object, double *point_on_object);
double			*sphere_normal(t_object *object, double *point_on_object);
double			*cone_normal(t_object *object, double *point_on_object);
double			*plane_normal(t_object *object, double *point_on_object);

void			solve_eq(double *inter_points, double *cof);

void			check_malloc(void *ptr);
void			error_file(void);

int				key_hook(int key, void *param);
int				expose_hook(void *param);

double	compute_reflection(t_light_st *lightstate, double light_intens, \
	double normal_dot_light, double *light_v);

#endif
