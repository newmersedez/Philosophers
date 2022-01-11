#include "../includes/philo.h"

int main(int argc, char *argv[])
{
    int     status_code;
    t_table table_info;

    status_code = 0;
    try_parse_args(argc, argv, &table_info, &status_code);
    if (status_code == ARGS_ERROR_CODE)
        return (ARGS_ERROR_CODE);
    return (0);
}
