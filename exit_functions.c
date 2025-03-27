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

        pthread_mutex_destroy(philo_to_free->fork);
        free(philo_to_free);
        philo_to_free = NULL;
    }
}

void	clean_up(t_philosophers **philosophers)
{
    size_t  index;

    index = 0;
	while (index < (*philosophers)->number_of_philosophers)
	{
		pthread_join((*philosophers)->philo->philosopher, NULL);
		(*philosophers)->philo = (*philosophers)->philo->next;
		index++;
	}
}