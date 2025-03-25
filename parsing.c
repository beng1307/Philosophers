#include "philo.h"

t_philo	*create_philos(size_t number_of_philosophers)
{
	t_philo	*list_of_philos;
	t_philo	*last_philo;
	size_t	index;

	index = 0;
	list_of_philos = NULL;
	while (index < number_of_philosophers)
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

static int number_validation(t_philosophers **philosophers)
{
	if ((*philosophers)->number_of_philosophers < 1)
		return (1);
	if ((*philosophers)->time_to_die < 1)
		return (1);
	if ((*philosophers)->time_to_eat < 1)
		return (1);
	if ((*philosophers)->time_to_sleep < 1)
		return (1);
	if ((*philosophers)->times_phils_have_to_eat < 1)
		return (1);
	
	return (0);
}

int	parse_and_init_philo(t_philosophers **philosophers, char **av)
{
	(*philosophers)->number_of_philosophers = philo_atoi(av[1]);
	(*philosophers)->time_to_die = philo_atoi(av[2]);
	(*philosophers)->time_to_eat = philo_atoi(av[3]);
	(*philosophers)->time_to_sleep = philo_atoi(av[4]);
	(*philosophers)->times_phils_have_to_eat = philo_atoi(av[4]); //check if its even there as input
	(*philosophers)->philo_dead = false;
	(*philosophers)->philo = create_philos((*philosophers)->number_of_philosophers);
	if (!(*philosophers)->philo)
		return (clean_exit());

	return (number_validation(philosophers));
}