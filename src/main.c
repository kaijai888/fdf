/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 17:31:46 by kzeng             #+#    #+#             */
/*   Updated: 2017/03/23 17:31:48 by kzeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Error codes
**	-8:	Different widths
**	-2:	Atoi error - not int?
**	-3:	Cannot open map
*/

void	ft_initialize(t_list **list)
{
	(*list)->mlx = mlx_init();
	(*list)->win = mlx_new_window((*list)->mlx, 1200, 1200, "FDF");
	(*list)->input = NULL;
	(*list)->length = -1;
	(*list)->width = -1;
	(*list)->min_height = 0;
	(*list)->height = -1;
	(*list)->range = 0;
	(*list)->px_height = 0;
	(*list)->curr_height = 0;
	(*list)->next_height = 0;
	(*list)->draw = 50;
	(*list)->map = NULL;
	(*list)->x = 0;
	(*list)->y = 0;
	(*list)->x1 = 0;
	(*list)->x2 = 0;
	(*list)->y1 = 0;
	(*list)->y2 = 0;
	(*list)->slope = 0;
	(*list)->i = 0;
	(*list)->num = 0;
	(*list)->len = 0;
	(*list)->neg = 0;
	(*list)->error = 0;
}

void	ft_free(t_list *list)
{
	int		i;

	free(list->mlx);
	free(list->win);
	if (list->input != NULL)
		free(list->input);
	if (list->map != NULL)
	{
		i = -1;
		while (++i < list->length)
			free(list->map[i]);
		free(list->map);
	}
	free(list);
}

int		key_hook(int keycode, t_list *list)
{
	ft_printf("key event:%d\n", keycode);
	if (keycode == 53)
		exit(0);
	if (keycode == 27 || keycode == 78)
	{
		mlx_clear_window(list->mlx, list->win);
		if (list->px_height > 0)
			list->px_height--;
		ft_draw(list);
	}
	else if (keycode == 24 || keycode == 69)
	{
		mlx_clear_window(list->mlx, list->win);
		list->px_height++;
		ft_draw(list);
	}
	return (keycode);
}

int		mouse_hook(int button, int x, int y, t_list *list)
{
	ft_printf("mouse event:%d\n", button);
	if (button == 1)
	{
		mlx_clear_window(list->mlx, list->win);
		list->x = x;
		list->y = y;
		ft_click_draw(list, x, y);
	}
	else if (button == 2)
	{
		mlx_clear_window(list->mlx, list->win);
		list->px_height = 0;
		ft_draw(list);
	}
	return (button);
}

int		main(int argc, char **argv)
{
	t_list	*list;

	if (argc == 2)
	{
		list = (t_list *)malloc(sizeof(t_list));
		ft_initialize(&list);
		ft_read_input(open(argv[1], O_RDONLY), list);
		while (list->draw > 1 && (((list->draw * list->width) > 1200) ||
			(((list->draw * (list->length + list->width)) +
			(list->range * 4)) > 1150)))
		{
			if ((list->length + list->width + (list->range * 4)) > 1150)
				break ;
			list->draw--;
		}
		if (list->error >= 0)
			ft_draw_handler(list);
		else
			ft_printf("Error\n");
		ft_free(list);
	}
	else
		ft_printf("Usage: ./fdf [map]\n");
	return (0);
}
