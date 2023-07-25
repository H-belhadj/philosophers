#include "philo.h"
void eat(t_philo *philo)
{
    printf("%ld ", time_cur(philo));
    printf("EATING\n");
    philo->last_eat = timer();
    philo->eat++;
    usleep(philo->data->time_to_eat * 1000);
}

void *diner(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    while(1)
    {
        ft_fork(philo);
        eat(philo);
        printf("%ld ", time_cur(philo));
        printf("SLEEP\n");
        usleep(philo->data->time_to_sleep * 1000);
        printf("%ld ", time_cur(philo));
        printf("THINKING\n");
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
        // cheack the last time eat whit this time now
        // if cur time - last time eat > time to die == kill the prossec and exit
        // if you the last argument == yes == cheack all the philos eat the last argument numbers and exit == no ==do nothing 
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
