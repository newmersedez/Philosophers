/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:53:56 by lorphan           #+#    #+#             */
/*   Updated: 2022/01/13 18:37:46 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
#include <stdio.h>

# define TRUE 1
# define FALSE 0

typedef struct s_philo
{
	pthread_t		terminator;
	pthread_t		philo_thread;
	pthread_mutex_t	eating_mutex;
	size_t			id;
	size_t			left_id;
	size_t			right_id;
	unsigned int	nta;
	unsigned int	lta;
}	t_philo;

typedef struct s_table
{
	int				optional_arg;
	unsigned int	nop;
	unsigned int	ttd;
	unsigned int	tte;
	unsigned int	tts;
	unsigned int	notepme;
	unsigned int	death;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	msg_mutex;
}	t_table;

/* Main Functions */

int		try_init_table(int argc, char *argv[], t_table *table_info);
void	deallocate_memory(t_table *table_info);

/* Libft Functions */

int	ft_isdigit(char c);
int	ft_atoi(const char *str);
int	ft_isnumber(const char *str);

#endif