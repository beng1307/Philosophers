#include "philo.h"

int	parse_and_init_philo(t_philo **philo, char **av)
{
	(*philo)->number_of_philosophers = philo_atoi(av[1]);
	(*philo)->time_to_die = philo_atoi(av[2]);
	(*philo)->time_to_eat = philo_atoi(av[3]);
	(*philo)->time_to_sleep = philo_atoi(av[4]);
	(*philo)->times_phils_have_to_eat = philo_atoi(av[4]);
}