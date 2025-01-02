#include "philo.h"

inline bool	is_not_a_digit(char character)
{
	return (!(character >= '0' && character <= '9'));
}

size_t	ft_strlen(char *str)
{
	size_t	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

size_t	philo_atoi(const char *str)
{
	size_t	number;

	number = 0;
	while (*str)
	{
		if (number > (SIZE_MAX - (*str - '0') / 10))
			return (SIZE_MAX);
		number = number * 10 + (*str++ - '0');
	}
	return (number);
}

size_t timestamp_in_ms(void)
{
	struct timeval	curr_time;

	gettimeofday(&curr_time, NULL);
	return ((curr_time.tv_sec * 1000) + (curr_time.tv_usec / 1000));
}