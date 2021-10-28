#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <memory.h>
# include <unistd.h>

typedef struct s_philosopher
{

}	t_philosopher;

typedef struct s_info
{
	size_t			philo_num;
	size_t			must_eat;
	__useconds_t	time_to_die;
	__useconds_t	time_to_eat;
	__useconds_t	time_to_sleep;
}	t_info;

#endif