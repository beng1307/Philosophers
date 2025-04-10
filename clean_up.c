#include "philo.h"

void	save_free(void **to_free)
{
	if (to_free && *to_free)
	{
		free(*to_free);
		*to_free = NULL;
	}
}

void    free_philos(t_data **data)
{
    t_philo *philo_to_free;

    if (!(*data)->philo)
        return ;
    while ((*data)->philo)
    {
        philo_to_free = (*data)->philo;
        (*data)->philo = philo->next;

        if (philo_to_free->fork)
            pthread_mutex_destroy(&philo_to_free->fork);
        save_free(&philo_to_free);
    }
}

void    join_threads(t_data **data)
{
    size_t  index;

    index = 0;
	while (index < (*data)->number_of_philos)
	{
        //maybe make a bool if its still running for checking
		pthread_join((*data)->philo->philosopher, NULL);
		(*data)->philo = (*data)->philo->next;
		index++;
	}
}

void    destroy_data(t_data **data)
{
    if ((*data)->print_mutex)
        pthread_mutex_destroy(&(*data)->print_mutex);
    if ((*data)->last_meal_time_mutex)
        pthread_mutex_destroy(&(*data)->last_meal_time_mutex);
    if ((*data)->philo_dead_mutex)
        pthread_mutex_destroy(&(*data)->philo_dead_mutex);

    save_free(data)
}

void	clean_up(t_data **data)
{
    join_threads(data);
    free_philos(data);
    destroy_data(data);
}