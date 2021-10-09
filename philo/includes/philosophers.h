/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 20:42:51 by lorphan           #+#    #+#             */
/*   Updated: 2021/10/09 21:25:25 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_info
{
	size_t	number_of_philosophers;
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
	size_t	number_of_times_each_philosopher_must_eat;
}	t_info;

/* Libft */

int	ft_atoi(const char *str);
int	ft_isnumber(char *s);

/* Parser */

int	set_default(t_info *info, int argc, char *argv);

#endif