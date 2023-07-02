#include "philo.h"
t_philo *new_philo(int value, t_list *list)
{
    t_philo *new_philo = malloc(sizeof(t_philo));
    new_philo->n_philo = value;
    new_philo->data = list;
    new_philo->eat = 0;
    new_philo->last_eat = timer();
    pthread_mutex_init(&new_philo->fork, NULL);
    return (new_philo);
}

void    philo_list(t_philo  **head, t_philo *new)
{
    if (!(*head))
    {
        new->next = new;
        new->prev = new;
        *head = new;
        return ;
    }
    new->prev = (*head)->prev;
    new->next = *head;
    (*head)->prev->next = new;
    (*head)->prev = new;
}

t_philo *ft_philo(t_list *list)
{
    int i;
    t_philo *philo;

    i = 0;
    philo = NULL;
    while(++i <= list->number_of_philosophers)
        philo_list(&philo, new_philo(i, list));
    return (philo);
}