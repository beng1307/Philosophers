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


// Structs
typedef struct	s_philo
{
	pthread_t		philosopher;
	int				id;

	pthread_mutex_t	*fork;
	size_t			last_meal_time;

	struct s_philo	*prev;
	struct s_philo	*next;
}					t_philo;

typedef struct	s_philosophers
{
	t_philo			*philo;

	size_t			number_of_philosophers;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			times_phils_have_to_eat;
	bool			philo_dead;
}					t_philosophers;


// Utils
size_t		ft_strlen(char *str);
size_t		philo_atoi(const char *str);
void		*ft_calloc(size_t nmemb, size_t size);
size_t 		timestamp_in_ms(void);
bool		is_not_a_digit(char character);


// Error handling
int		wrong_input(int ac, char **av);
int		an_arg_is_not_correct(char **av);
void	error_message(char *message);
int		wrong_input(int ac, char **av);


// Linked-list functions
t_philo *ft_newphilo(int id);
t_philo	*ft_last_philo(t_philo *philo);
int	    philo_add_back(t_philo **philo_list, t_philo *new_philo);


// Tasks
void	thinking(t_philosophers **philosophers, t_philo *philo);
void	take_fork(t_philosophers **philosophers, t_philo *philo);
void	eating(t_philosophers **philosophers, t_philo *philo);
void	sleeping(t_philosophers **philosophers, t_philo *philo);
void	died(t_philosophers **philosophers, t_philo *philo);
bool	all_alive(t_philosophers **philosophers);


// Parsing
int		parse_and_init_philo(t_philosophers **philosophers, char **av);


// Clean up
void	clean_up(t_philosophers **philosophers);
void    free_philos(t_philo *philos);


#endif