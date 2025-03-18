#include "philo.h"

int	wrong_input(int ac, char **av)
{
	if (!(ac == 5 || ac == 6))
		return (1);
	if (an_arg_is_not_correct(av))
		return (1);
}

void	philo_while_loop(t_philo **philo)
{
	while (1)
	{
		
	}
}

int	main(int ac, char **av)
{
	t_philosophers	*philosophers;

	philosophers = malloc(sizeof(t_philosophers));
	if (!philosophers)
		return (error_message("Allocation failed!"), 1);
	if (wrong_input(ac, av))
		return (error_message("Put only numbers!"), 1);
	if (parse_and_init_philo(&philosophers, av) == 1)
		return (error_message("Input not valid!"), 1);
	philo_while_loop(&philosophers);
}