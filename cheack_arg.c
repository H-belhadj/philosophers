#include "philo.h"

int cheack(int argc, char **argv)
{
    if (argc != 5 && argc != 6)
        return (write_error("Check the number of arguments\n"));
    if (!ft_validint(argv[1]) || !ft_validint(argv[2]) || !ft_validint(argv[3]) || !ft_validint(argv[4]))
        return (write_error("One of your arguments is neither a time nor a number\n"));
    if (argc == 6 && !ft_validint(argv[5]))
        return (write_error("Time to eat\n"));
    if (ft_atoi(argv[1]) < 0 || ft_atoi(argv[1]) > INT_MAX)
        return (write_error("philo's number is wrong\n"));
    if (ft_atoi(argv[2]) == 0 || ft_atoi(argv[2]) > INT_MAX)
        return (write_error("Die's time is wrong\n"));
    if (ft_atoi(argv[3]) == 0 || ft_atoi(argv[3]) > INT_MAX)
        return (write_error("eat's time is wrong\n"));
    if (ft_atoi(argv[4]) == 0 || ft_atoi(argv[4]) > INT_MAX)
        return (write_error("sleep's time is wrong\n"));
    if (argc == 6 && (ft_atoi(argv[5]) < 0 || ft_atoi(argv[5]) > INT_MAX))
        return (write_error("number of must eat is wrong\n"));
    if (argc == 6 && ft_atoi(argv[5]) == 0)
        return 1;
    return 0;
}