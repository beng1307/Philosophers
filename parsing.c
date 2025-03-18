#include "philo.h"

static void	create_philos(t_philosophers **philosophers)
{
	size_t	index;

	index = 0;
	while (index < (*philosophers)->number_of_philosophers)
	{
		(*philosophers)->philo = ;
		index++;
	}

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
	(*philosophers)->times_phils_have_to_eat = philo_atoi(av[4]);

	create_philos(philosophers);

	return (number_validation(philosophers));
}