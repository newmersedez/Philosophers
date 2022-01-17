#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <semaphore.h>
# include <sys/time.h>

# define TRUE 1
# define FALSE 0

typedef struct s_philo
{
	pthread_t		terminator_thread;
	sem_t			eating_semaphore;
	unsigned int	id;
	unsigned int	number_of_ate;
	time_t			last_time_ate;
	struct s_table	*table_info;
}   t_philo;

typedef struct s_table
{
    unsigned int nop;
    unsigned int ttd;
    unsigned int tte;
    unsigned int tts;
    unsigned int notepme;

}   t_table;

/* Main Functions */

int	try_parse_args(int argc, char *argv[], t_table *table_info);

/* Libft Functions */

int ft_isdigit(char c);
int	ft_atoi(const char *str);
int ft_isnumber(const char *str);

#endif