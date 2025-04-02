#include "philo.h"

void    free_philos(t_philo *philos)
{
    t_philo *philo_to_free;

    if (!philos)
        return ;
    while (philos)
    {
        philo_to_free = philos;
        philos = philos->next;

        pthread_mutex_destroy(&philo_to_free->fork);
        free(philo_to_free);
        philo_to_free = NULL;
    }
}

void	clean_up(t_data **data)
{
    size_t  index;

    index = 0;
	while (index < (*data)->number_of_philos)
	{
		pthread_join((*data)->philo->philosopher, NULL);
		(*data)->philo = (*data)->philo->next;
		index++;
	}
}