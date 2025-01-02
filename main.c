#include "philo.h"

int	wrong_input(int ac, char **av)
{
	if (!(ac == 5 || ac == 6))
		return (1);
	if (an_arg_is_not_correct(av))
		return (1);
	return (0);
}

void	philo_while_loop()
{
	while (1)
	{

	}
}

int	main(int ac, char **av)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (error_message("Allocation failed!"), 1);
	if (wrong_input(ac, av))
		return (error_message("Put only numbers!"), 1);
	parse_and_init_philo(&philo);
	philo_while_loop();
}