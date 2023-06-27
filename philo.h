#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>     // For standard input/output functions
#include <stdlib.h>    // For general-purpose functions such as memory allocation
#include <pthread.h>   // For thread creation and synchronization
#include <unistd.h>    // For sleep() function (optional)
#include <limits.h>    // For INT_MAX && INT_MIN

typedef struct s_list {
    int number_of_philosophers;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_of_times_each_philosopher_must_eat;
} t_list;

typedef struct s_philo{
    int n_philo;
    t_list  *data;
    struct s_philo *next;
    struct s_philo *prev;
}t_philo;

int     cheack(int ac, char **av);
t_list  *arg_value(t_list *list, int argc, char **argv);
int     ft_atoi(char *str);
int     ft_isdigit(int c);
int     ft_validint(char *str);
void    ft_putchar(char c);
int     write_error(char *str);
void    ft_putstr(char *str);
t_philo *ft_philo(t_list *list);

#endif
