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
	if ((*data)->number_of_data < 1)
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
	(*data)->number_of_data = philo_atoi(av[1]);
	(*data)->time_to_die = philo_atoi(av[2]);
	(*data)->time_to_eat = philo_atoi(av[3]);
	(*data)->time_to_sleep = philo_atoi(av[4]);
	(*data)->times_phils_have_to_eat = philo_atoi(av[4]);
	(*data)->philo_dead = false;
	(*data)->dining_started = false;
	(*data)->mutex = ft_calloc(1, sizeof(pthread_mutex_t));
	if (!(*data)->mutex)
		return (1);
	(*data)->philo = create_philos((*data)->number_of_data);
	if (!(*data)->philo)
		return (free((*data)->mutex), 1);
	pthread_mutex_init((*data)->mutex, NULL);
	pthread_mutex_init();

	return (number_validation(data));
}