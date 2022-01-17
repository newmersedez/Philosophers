#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/types.h>
# include <semaphore.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/wait.h>
# include <pthread.h>

# define TRUE 1
# define FALSE 0

# define PHILO_TAKE_FORK 0
# define PHILO_EAT 1
# define PHILO_SLEEP 2
# define PHILO_THINK 3
# define PHILO_DIED 4

typedef struct s_philo
{
	pthread_t		terminator_thread;
	sem_t			*eating_sem;
	size_t			id;
	pid_t			pid;
	unsigned int	number_of_ate;
	time_t			last_time_ate;
	struct s_table	*table_info;
}   t_philo;

typedef struct s_table
{	
    unsigned int 	num_of_philos;
    unsigned int 	time_to_die;
    unsigned int 	time_to_eat;
    unsigned int 	time_to_sleep;
    unsigned int 	notepme;
	time_t			start_time;
	pthread_t		eat_counter;
	t_philo			**philos;
	sem_t			*forks_sem;
	sem_t			*msg_sem;
	sem_t			*death_sem;
	sem_t			*eating_sem;
}   t_table;

/* Main Functions */

int		try_parse_args(int argc, char *argv[], t_table *table_info);
void	start_philosophers(t_table *table_info);
void	*philo_routins(t_philo *philo);
time_t	current_time(void);
void	display_message(t_philo *philo, unsigned int type);

/* Libft Functions */

int ft_isdigit(char c);
int	ft_atoi(const char *str);
int ft_isnumber(const char *str);

#endif