/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_content.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:52:21 by rel-mora          #+#    #+#             */
/*   Updated: 2025/03/17 15:52:23 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_check_file(char *av)
{
	size_t	len;

	len = ft_strlen(av) - 1;
	if (av[len] != 'b')
		return (0);
	len--;
	if (av[len] != 'u')
		return (0);
	len--;
	if (av[len] != 'c')
		return (0);
	len--;
	if (av[len] != '.')
		return (0);
	return (1);
}

int	check_empt_line_map(char *str, int i)
{
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] && str[i + 1] == '\n')
		{
			free(str);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_empty_line(char *joined)
{
	t_joined	info;

	info.i = 0;
	info.count = 0;
	info.str = ft_strtrim(joined, "\n");
	if (!info.str)
		return (1);
	while (info.str[info.i])
	{
		if (info.str[info.i] == '\n' && info.count < 7)
			info.i++;
		if (info.str[info.i] != '\n' && info.count < 7)
		{
			while (info.str[info.i] && info.str[info.i] != '\n')
				info.i++;
			if (info.str[info.i] && info.str[info.i] == '\n')
				info.count++;
		}
		if (info.count == 7)
			break ;
	}
	if (check_empt_line_map(info.str, info.i))
		return (1);
	return (free(info.str), 0);
}

char	**ft_fill_content(char **content, char *av)
{
	int		fd;
	char	*line;
	char	*joined;

	joined = NULL;
	line = NULL;
	fd = open(av, O_RDONLY);
	if (fd == -1)
		ft_just_print_error("Error: Failed to open the file\n");
	line = get_next_line(fd);
	while (line != NULL)
	{
		joined = ft_strjoin(joined, line);
		line = get_next_line(fd);
	}
	free(line);
	content = ft_split(joined, '\n');
	if (check_empty_line(joined) || !content)
	{
		free(joined);
		free_double(content);
		ft_put_error("Error: emply line.\n", NULL, NULL);
	}
	free(joined);
	return (content);
}

void	ft_validate(char *av, t_start *var)
{
	if (ft_check_file(av))
	{
		var->content = ft_fill_content(var->content, av);
		fill_config(var);
		fill_map(var);
	}
	else
	{
		printf("Error:\n ");
		ft_just_print_error("There is no file with the extension .cub.\n");
	}
}
