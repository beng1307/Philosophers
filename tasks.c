#include "philo.h"

void	take_fork(int philo_n)
{
	printf("%zu %d has taken fork\n", timestamp_in_ms(), philo_n);
}

void	eating(int philo_n)
{
	printf("%zu %d is eating\n", timestamp_in_ms(), philo_n);
}

void	sleeping(int philo_n)
{
	printf("%zu %d is sleeping\n", timestamp_in_ms(), philo_n);
}

void	thinking(int philo_n)
{
	printf("%zu %d is thinking\n", timestamp_in_ms(), philo_n);
}

void	died(int philo_n)
{
	printf("%zu %d died\n", timestamp_in_ms(), philo_n);
}


