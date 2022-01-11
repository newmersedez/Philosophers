#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <unistd.h>

# define TRUE 1
# define FALSE 0
# define ARGS_ERROR_CODE 1

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

void    try_parse_args(int argc, char *argv[], t_table *table_info, int *code);

#endif