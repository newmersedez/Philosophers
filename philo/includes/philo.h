/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:53:56 by lorphan           #+#    #+#             */
/*   Updated: 2022/01/14 01:36:38 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/types.h>
# include <sys/time.h>

# define TRUE 1
# define FALSE 0

# define PHILO_TAKE_FORK 0
# define PHILO_EAT 1
# define PHILO_THINK 2
# define PHILO_SLEEP 3
# define PHILO_DIED 4

typedef struct s_philo
{
	pthread_t		philo_thread;
	pthread_t		terminator_thread;
	pthread_mutex_t	eating_mutex;
	int				is_eating;
	size_t			id;
	size_t			left_id;
	size_t			right_id;
	unsigned int	number_of_ate;
	time_t			last_time_ate;
	struct s_table	*table_info;
}	t_philo;

typedef struct s_table
{
	int				optional_arg;
	unsigned int	num_of_philos;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	notepme;
	unsigned int	death;
	t_philo			**philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	msg_mutex;
	time_t			start_time;
}	t_table;

/* Main Functions */

int		try_init_table(int argc, char *argv[], t_table *table_info);
void	deallocate_memory(t_table *table_info);
void	start_philosophers(t_table *table_info);
void	philo_routins(t_philo *philo);
time_t	time_in_ms(void);
void	display_message(t_table *table_info, t_philo *philo, unsigned int type);

/* Libft Functions */

int	ft_atoi(const char *str);
int	ft_isdigit(char c);
int	ft_isnumber(const char *str);

#endif