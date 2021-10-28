#include "../includes/philosophers.h"

int	main(int argc, char *argv[])
{
	t_info	info;

	if (!parse_program_arguments(argc, argv, &info))
		return (1);
	return (0);
}
