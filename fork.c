/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 22:11:03 by hbelhadj          #+#    #+#             */
/*   Updated: 2023/08/10 01:09:53 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_fork(t_philo *philo)
{
    pthread_mutex_lock(&philo->fork);
    pthread_mutex_lock(&philo->data->write);
    if(philo->data->is_end == 1)
        return ;
    ft_print("TAKE THE RIGHT FORk\n", philo);
    pthread_mutex_unlock(&philo->data->write);
    pthread_mutex_lock(&philo->next->fork);
    pthread_mutex_lock(&philo->data->write);
    
    if(philo->data->is_end == 1)
        return ;
    ft_print("TAKE THE left FORK\n", philo);
    pthread_mutex_unlock(&philo->data->write);
}
