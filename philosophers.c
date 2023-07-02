#include "philo.h"
void eat(t_philo *philo)
{
    printf("%ld ", time_cur(philo));
    printf("EATING\n");
    philo->last_eat = timer();
    philo->eat++;
    
}

void *diner(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    while(1)
    {
        ft_fork(philo);
        eat(philo);
        pthread_mutex_unlock(&philo->fork);
        pthread_mutex_unlock(&philo->next->fork);
        
        
    }
}

void cena(t_philo *philo)
{
    int i;
    
    i = 0;
    while(++i <= philo->data->number_of_philosophers)
    {
        if(pthread_create(&philo->thread, NULL, &diner, philo))
            return ;
        philo = philo->next;
        usleep(100);
    }
    
    while (1)
    {
        /* code */
    }
    
}

int main(int argc, char **argv)
{
    t_list  *list;
    t_philo *philo;
    
    philo = NULL;
    list = malloc(sizeof(t_list));
    if (cheack(argc, argv))
        return 1;
    list = arg_value(&list, argc, argv);
    philo = ft_philo(list);
    if(!philo)
        return(1);
    cena(philo);
    return 0;
}
