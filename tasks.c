#include "philo.h"

void	thinking(t_philosophers **philosophers, t_philo *philo)
{
	if (!(*philosophers)->philo_dead)
		printf("%zu %d is thinking\n", timestamp_in_ms(), philo->id);
}

void	take_fork(t_philosophers **philosophers, t_philo *philo)
{
	if ((*philosophers)->philo->id % 2 == 0) 
	{
		pthread_mutex_lock(philo->fork);
		pthread_mutex_lock(philo->next->fork);
	}
	else
	{
		pthread_mutex_lock(philo->next->fork);
		pthread_mutex_lock(philo->fork);
	}
	if (!(*philosophers)->philo_dead)
		printf("%zu %d has taken fork\n", timestamp_in_ms(), (*philosophers)->philo->id);
}

void	eating(t_philosophers **philosophers, t_philo *philo)
{
	//philo starts eating
	if (!(*philosophers)->philo_dead)
		printf("%zu %d is eating\n", timestamp_in_ms(), philo->id);
	philo->last_meal_time = timestamp_in_ms();
	usleep((*philosophers)->time_to_eat);
	
	//philo finished eating
	pthread_mutex_unlock(philo->fork);
	pthread_mutex_unlock(philo->next->fork);
}

void	sleeping(t_philosophers **philosophers, t_philo *philo)
{
	//start sleeping
	if (!(*philosophers)->philo_dead)
		printf("%zu %d is sleeping\n", timestamp_in_ms(), philo->id);
	usleep((*philosophers)->time_to_sleep);
	//finished sleeping
}

void	died(t_philosophers **philosophers, t_philo *philo)
{
	(*philosophers)->philo_dead = true;
	printf("%zu %d died\n", timestamp_in_ms(), philo->id);
}

bool	all_alive(t_philosophers **philosophers)
{
	t_philo	*philos;
	size_t	index;

	philos = (*philosophers)->philo;
	index = 0;
	while (index < (*philosophers)->number_of_philosophers)
	{
		if (timestamp_in_ms() - philos->last_meal_time > (*philosophers)->time_to_die)
			return (died(philosophers, philos), false);
		philos = philos->next;
	}
	return (true);
}


