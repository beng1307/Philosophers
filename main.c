#include "philo.h"

static void	*philos_life(void *data_content)
{
	t_data	**data;
	t_philo	*curr_philo;

	
	data = (t_data **)data_content;
	curr_philo = (*data)->philo;
	curr_philo->last_meal_time = timestamp_in_ms();	

	while (1)
	{
		take_fork(data, curr_philo);
		eating(data, curr_philo);
		sleeping(data, curr_philo);
		thinking(data, curr_philo);
	}
	return (NULL);
}

static void	philo_while_loop(t_data **data)
{
	size_t	index;

	index = 0;
	(*data)->starting_time = timestamp_in_ms();
	while (1)
	{
		while (index < (*data)->number_of_philos)
		{
			pthread_create(&(*data)->philo->philosopher, NULL, philos_life, (void *)data);
			usleep(10);
			(*data)->philo = (*data)->philo->next;
			index++;		
		}


		// (*data)->dining_started = true;
		// if (!all_alive(data))
		// 	break ;
	}
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = ft_calloc(sizeof(t_data) + 1, 1);
	if (!data)
		return (error_message("Allocation failed!"), 1);
	if (wrong_input(ac, &av[1]))
		return (free(data), error_message("Put only numbers!"), 1);
	if (parse_and_init_philo(&data, av) == 1)
		return (error_message("Input not valid!"), 1);
	philo_while_loop(&data);


	// clean_up(&data);
	// free_philos(data->philo);
	// free(data);
}
