/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 22:11:03 by hbelhadj          #+#    #+#             */
/*   Updated: 2023/07/01 23:15:17 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_fork(t_philo *philo)
{
    pthread_mutex_lock(&philo->fork);
    printf("%ld ", time_cur(philo));
    printf("TAKE THE RIGHT FORK\n");
    pthread_mutex_lock(&philo->next->fork);
    printf("%ld ", time_cur(philo));
    printf("TAKE THE left FORK\n");
}
