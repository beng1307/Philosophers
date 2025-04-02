#include "philo.h"

t_philo	*create_philos(size_t number_of_data)
{
	t_philo	*list_of_philos;
	t_philo	*last_philo;
	size_t	index;

	index = 0;
	list_of_philos = NULL;
	while (index < number_of_data)
	{
		if (philo_add_back(&list_of_philos, ft_newphilo(index + 1)) == 1)
			return (NULL);
		index++;
	}
	last_philo = ft_last_philo(list_of_philos);
	list_of_philos->prev = last_philo;
	last_philo->next = list_of_philos;
	return (list_of_philos);
}

static int number_validation(t_data **data)
{
	if ((*data)->number_of_philos < 1)
		return (1);
	if ((*data)->time_to_die < 1)
		return (1);
	if ((*data)->time_to_eat < 1)
		return (1);
	if ((*data)->time_to_sleep < 1)
		return (1);
	if ((*data)->times_phils_have_to_eat < 1)
		return (1);
	
	return (0);
}

int	parse_and_init_philo(t_data **data, char **av)
{
	(*data)->number_of_philos = philo_atoi(av[1]);
	(*data)->time_to_die = philo_atoi(av[2]);
	(*data)->time_to_eat = philo_atoi(av[3]);
	(*data)->time_to_sleep = philo_atoi(av[4]);
	(*data)->times_phils_have_to_eat = philo_atoi(av[4]);
	(*data)->philo_dead = false;

	if (pthread_mutex_init(&(*data)->print_mutex, NULL) != 0)
		return (clean_up(data), 1);
	if (pthread_mutex_init(&(*data)->time_to_eat_mutex, NULL) != 0)
		return (clean_up(data), 1);
	if (pthread_mutex_init(&(*data)->philo_dead_mutex, NULL) != 0)
		return (clean_up(data), 1);
	if (pthread_mutex_init(&(*data)->last_meal_time_mutex, NULL) != 0)
		return (clean_up(data), 1);

	(*data)->philo = create_philos((*data)->number_of_philos);
	if (!(*data)->philo)
		return (clean_up(data), 1);

	return (number_validation(data));
}