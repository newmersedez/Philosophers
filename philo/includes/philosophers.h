#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <memory.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_info
{
	int	philo_num;
	int	must_eat;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
}	t_info;

typedef struct s_philosopher
{
	t_info	info;
}	t_philosopher;

/* Libft */

int	ft_isdigit(char c);
int	ft_atoi(const char *str);

/* Main functions */

int	parse_program_arguments(int argc, char *argv[], t_info *info);

#endif