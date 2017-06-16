/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 17:31:46 by kzeng             #+#    #+#             */
/*   Updated: 2017/03/23 17:31:48 by kzeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define MAX(x, y) (x > y ? x : y)
# define MIN(x, y) (x > y ? y : x)
# define BUFF_SIZE 42
# define MAX_FD 42
# define MALLOC_CHECK(x) if (x == NULL) {return (-1);}
# define READ_CHECK(x) if (x == -1) {free(buf); return (-1);}

# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_list
{
	void		*mlx;
	void		*win;
	char		*input;
	int			length;
	int			width;
	int			min_height;
	int			height;
	int			range;
	int			px_height;
	int			curr_height;
	int			next_height;
	int			draw;
	int			**map;
	int			x;
	int			y;
	int			x1;
	int			x2;
	int			y1;
	int			y2;
	float		slope;
	int			i;
	int			num;
	int			len;
	int			neg;
	int			error;
}				t_list;

/*
**	ft_draw.c
*/
void			ft_draw_line(t_list *list, int c, int s1, int s2);
int				ft_draw_flat_helper(t_list *list, int y1, int x2, int y2);
int				ft_draw_flat_helper2(t_list *list, int y1, int x2, int y2);
void			ft_draw_flat(t_list *list, int y1, int x2, int y2);

/*
**	ft_draw2.c
*/
void			ft_draw_i_helper(t_list *list, int diff, int int_y, int c);
void			ft_draw_i(t_list *list, int x1, float y1, float dx);
void			ft_draw_ii_helper(t_list *list, int diff, int int_y, int c);
void			ft_draw_ii(t_list *list, int x1, float y1, float dx);

/*
**	ft_draw3.c
*/
void			ft_draw_iii_helper(t_list *list, int diff, int int_y, int c);
void			ft_draw_iii(t_list *list, int x1, float y1, float dx);
void			ft_draw_iv_helper(t_list *list, int diff, int int_y, int c);
void			ft_draw_iv(t_list *list, int x1, float y1, float dx);

/*
**	ft_draw_handler.c
*/
int				ft_color(t_list *list, float height);
void			ft_draw_helper(t_list *list, int i, int j);
void			ft_draw(t_list *list);
void			ft_click_draw(t_list *list, int x, int y);
void			ft_draw_handler(t_list *list);

/*
**	ft_helper.c
*/
int				ft_nwords(char *s, char c, int i);
char			**ft_strsplit(char *s, char c);

/*
**	ft_helper2.c
*/
char			*ft_strsub(char *s, unsigned int start, size_t len);
char			*ft_strnew(size_t size);
char			*ft_strdup(char *s1);
char			*ft_strcpy(char *dst, char *src);
char			*ft_strncat(char *s1, char *s2, size_t n);

/*
**	ft_lemin_helper3.c
*/
int				ft_strcmp(char *s1, char *s2);
size_t			ft_strlen(char *str);
int				ft_isdigit(int c);
int				ft_atoi(t_list *list, char *num);

/*
**	ft_parse_input.c
*/
void			ft_store_input(t_list *list, int i, int j, int k);
void			ft_parse_line(char *line, t_list *list);
void			ft_read_input(int fd, t_list *list);

/*
**	ft_printf.c
*/
void			ft_putchar(char c);
void			ft_putstr(const char *s);
void			ft_putnbr(int nb);
int				ft_printf(const char *format, ...);

/*
**	get_next_line.c
*/
int				get_next_line(const int fd, char **line);

/*
**	main.c
*/
void			ft_initialize(t_list **list);
void			ft_free(t_list *list);
int				key_hook(int keycode, t_list *list);
int				mouse_hook(int button, int x, int y, t_list *list);

#endif
