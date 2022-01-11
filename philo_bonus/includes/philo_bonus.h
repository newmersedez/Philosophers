#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# define TRUE 1
# define FALSE 0

typedef struct s_philo
{

}   t_philo;

typedef struct s_table
{
    int          optional_arg;
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