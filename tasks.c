#include "philo.h"

void	thinking(t_philosophers **philosophers, t_philo *philo)
{
	if (!(*philosophers)->philo_dead)
		printf("%zu %d is thinking\n", timestamp_in_ms(), philo->id);
}

// void	print_func(t_philosophers **philosophers)
// {
// 	PRINT MUTEX LOCK
//  PHILO_DEAD  LOCK
// 	if ((*philosophers)->philo_dead)
// 		return (mutex_unlock)
//	PHILO_DEAD UNLOCK
// 	printf("%zu %d has taken fork\n", timestamp_in_ms(), (*philosophers)->philo->id);
// 	PRINT MUTEX UNLOCK
// }

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
	//IF TRYING TO ACCES A VALUE IN MAIN STRUCT FROM THREAD LIKE PHILO DEAD, MUTEX LOCK MUTEX UNLOCK
	if (!(*philosophers)->philo_dead) //print mutex --> check if dead before printing
		printf("%zu %d has taken fork\n", timestamp_in_ms(), (*philosophers)->philo->id);
}

void	eating(t_philosophers **philosophers, t_philo *philo)
{
	//philo starts eating
	if (!(*philosophers)->philo_dead)
		printf("%zu %d is eating\n", timestamp_in_ms(), philo->id);
	//mutx
	philo->last_meal_time = timestamp_in_ms();
	//unlock
	usleep((*philosophers)->time_to_eat * 1000);
	pthread_mutex_unlock(philo->fork);
	pthread_mutex_unlock(philo->next->fork);
	//philo finished eating
}

void	sleeping(t_philosophers **philosophers, t_philo *philo)
{
	//start sleeping
	if (!(*philosophers)->philo_dead)
		printf("%zu %d is sleeping\n", timestamp_in_ms(), philo->id);
	usleep((*philosophers)->time_to_sleep * 1000);
	//finished sleeping
}

void	died(t_philosophers **philosophers, t_philo *philo)
{
	//MUTEX
	(*philosophers)->philo_dead = true;
	//MUTEX UNLOCK
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
		//lock
		if (timestamp_in_ms() - philos->last_meal_time > (*philosophers)->time_to_die)
			return (died(philosophers, philos), false);
		//unlock mealtime
		philos = philos->next;
	}
	return (true);
}


