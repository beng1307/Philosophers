#include "philo.h"

void	thinking(t_data **data, t_philo *philo)
{
	if (!(*data)->philo_dead)
		printf("%zu %d is thinking\n", timestamp_in_ms(), philo->id);
}

void	take_fork(t_data **data, t_philo *philo)
{
	pthread_mutex_lock(philo->fork);
	pthread_mutex_lock(philo->next->fork);
	//IF TRYING TO ACCES A VALUE IN MAIN STRUCT FROM THREAD LIKE PHILO DEAD, MUTEX LOCK MUTEX UNLOCK
	if (!(*data)->philo_dead)
		printf("%zu %d has taken fork\n", timestamp_in_ms(), (*data)->philo->id);
}

void	eating(t_data **data, t_philo *philo)
{
	if (!(*data)->philo_dead)
		printf("%zu %d is eating\n", timestamp_in_ms(), philo->id);
	//mutx
	philo->last_meal_time = timestamp_in_ms();
	//unlock
	usleep((*data)->time_to_eat * 1000);
	pthread_mutex_unlock(philo->fork);
	pthread_mutex_unlock(philo->next->fork);
}

void	sleeping(t_data **data, t_philo *philo)
{
	//start sleeping
	if (!(*data)->philo_dead)
		printf("%zu %d is sleeping\n", timestamp_in_ms(), philo->id);
	usleep((*data)->time_to_sleep * 1000);
	//finished sleeping
}

void	died(t_data **data, t_philo *philo)
{
	//MUTEX
	(*data)->philo_dead = true;
	//MUTEX UNLOCK
	printf("%zu %d died\n", timestamp_in_ms(), philo->id);
}

bool	all_alive(t_data **data)
{
	t_philo	*philos;
	size_t	index;

	philos = (*data)->philo;
	index = 0;
	while (index < (*data)->number_of_data)
	{
		//lock
		if (timestamp_in_ms() - philos->last_meal_time > (*data)->time_to_die)
			return (died(data, philos), false);
		//unlock mealtime
		philos = philos->next;
	}
	return (true);
}


