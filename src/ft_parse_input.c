/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 18:07:09 by kzeng             #+#    #+#             */
/*   Updated: 2017/04/19 18:07:10 by kzeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_read_free(char **split)
{
	int		i;

	i = -1;
	if (split != NULL)
	{
		while (split[++i] != 0)
			free(split[i]);
		free(split);
	}
}

void	ft_store_input(t_list *list, int i, int j, int k)
{
	char	**split;

	split = ft_strsplit(list->input, ' ');
	list->map = (int **)malloc(sizeof(int *) * list->length);
	while (++i < list->length)
	{
		list->map[i] = (int *)malloc(sizeof(int) * list->width);
		j = -1;
		while (++j < list->width)
		{
			list->map[i][j] = ft_atoi(list, split[k]);
			k++;
		}
	}
	list->range = list->height - list->min_height;
	ft_read_free(split);
}

void	ft_parse_line(char *line, t_list *list)
{
	int		i;
	char	**split;

	split = ft_strsplit(line, ' ');
	if (list->length == -1)
		list->length = 1;
	else
		list->length++;
	if (list->width == -1)
		list->width = ft_nwords(line, ' ', 0);
	else if (list->width != ft_nwords(line, ' ', 0))
		list->error = -8;
	i = 0;
	while (split[i] != '\0' && list->error >= 0)
	{
		ft_atoi(list, split[i]);
		if (list->error == -1)
			list->error = -2;
		list->height = MAX(list->height, list->num);
		list->min_height = MIN(list->min_height, list->num);
		i++;
	}
	ft_read_free(split);
}

void	ft_read_input(int fd, t_list *list)
{
	char	*line;
	char	*old;

	if (fd < 0)
		list->error = -3;
	while (get_next_line(fd, &line) > 0 && list->error >= 0)
	{
		ft_printf("%s\n", line);
		if (list->input == NULL)
			list->input = ft_strdup(line);
		else
		{
			old = list->input;
			list->input = ft_strnew(ft_strlen(old) + ft_strlen(line) + 1);
			ft_strcpy(list->input, old);
			ft_strncat(list->input, " ", 1);
			ft_strncat(list->input, line, ft_strlen(line));
			free(old);
		}
		ft_parse_line(line, list);
		free(line);
	}
	if (list->error >= 0 && list->input != NULL)
		ft_store_input(list, -1, -1, 0);
}
