#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/time.h>
#include <stdbool.h>

size_t	ft_strlen(char *str);

typedef struct	s_philo
{
	pthread_t		philosopher;
	int				id;

	size_t			number_of_philosophers;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			times_phils_have_to_eat;

	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}					t_philo;

#endif