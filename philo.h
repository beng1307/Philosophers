#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/time.h>
#include <stdbool.h>
#include <limits.h>

// Utils
size_t	ft_strlen(char *str);
size_t	philo_atoi(const char *str);


// Error handling
int		an_arg_is_not_correct(char **av);
void	error_message(char *message);
int		wrong_input(int ac, char **av);


// Parsing
int		parse_and_init_philo(t_philo **philo, char **av);


// Structs
typedef struct	s_philo
{
	pthread_t		philosopher;
	int				id;

	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}					t_philo;

typedef struct	s_philosophers
{
	t_philo			*philo;

	size_t			number_of_philosophers;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			times_phils_have_to_eat;
}					t_philosophers;

#endif