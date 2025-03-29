#include "philo.h"

static void	*philos_life(void *philosophers_data)
{
	t_philosophers	**philosophers;
	t_philo			*curr_philo;

	philosophers = (t_philosophers **)philosophers_data;
	curr_philo = (*philosophers)->philo;
	curr_philo->last_meal_time = timestamp_in_ms();
	//start if bool sim start is true
	while (1)
	{
		take_fork(philosophers, curr_philo);
		eating(philosophers, curr_philo);
		sleeping(philosophers, curr_philo);
		thinking(philosophers, curr_philo);
	}
	return (NULL);
}

static void	philo_while_loop(t_philosophers **philosophers)
{
	size_t	index;
	bool	already_done;

	index = 0;
	already_done = false;
	while (1)
	{
		while (index < (*philosophers)->number_of_philosophers && !already_done)
		{
			if (!already_done)
				already_done = true;
			pthread_create(&(*philosophers)->philo->philosopher, NULL, philos_life, (void *)philosophers);
			(*philosophers)->philo = (*philosophers)->philo->next;
			index++;
		}
		//bool sim start
		if (!all_alive(philosophers))
			break ;
		//uslpee(100)
	}
}

int	main(int ac, char **av)
{
	t_philosophers	*philosophers;

	philosophers = ft_calloc(sizeof(t_philosophers) + 1, 1);
	if (!philosophers)
		return (error_message("Allocation failed!"), 1);
	if (wrong_input(ac, &av[1]))
		return (free(philosophers), error_message("Put only numbers!"), 1);
	if (parse_and_init_philo(&philosophers, av) == 1)
		return (error_message("Input not valid!"), 1);
	philo_while_loop(&philosophers);


	clean_up(&philosophers);
	free_philos(philosophers->philo);
	free(philosophers);
}
