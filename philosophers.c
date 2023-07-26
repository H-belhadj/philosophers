#include "philo.h"
void ft_usleep(long time)
{
    long at_moment;

    at_moment = timer();
    while(timer() < time + at_moment)
        usleep(500);
}
void ft_print(char *str, t_philo *philo)
{
    long    time;

    time = time_cur(philo);
    printf("%ld PHILO %d %s", time, philo->n_philo, str);

}
void eat(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->write);
    ft_print("EATING\n", philo);
    pthread_mutex_unlock(&philo->data->write);
    pthread_mutex_lock(&philo->data->die);
    philo->last_eat = timer();
    pthread_mutex_unlock(&philo->data->die);
    pthread_mutex_lock(&philo->data->eat);
    philo->eat++;
    pthread_mutex_unlock(&philo->data->eat);
    ft_usleep(philo->data->time_to_eat);
    pthread_mutex_unlock(&philo->fork);
    pthread_mutex_unlock(&philo->next->fork);
}

void *diner(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    while(1)
    {
        ft_fork(philo);
        eat(philo);
        pthread_mutex_lock(&philo->data->write);
        ft_print("SLEPING\n", philo);
        pthread_mutex_unlock(&philo->data->write);
        ft_usleep(philo->data->time_to_sleep);
        pthread_mutex_lock(&philo->data->write);
        ft_print("THINKING\n", philo);
        pthread_mutex_unlock(&philo->data->write);
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
