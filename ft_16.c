#include "ft_printf.h"

int	get_size(unsigned long long int num)
{
	int	i;

	i = 0;
	if (num == 0)
		return (i);
	while (num)
	{
		num /= 16;
		i++;
	}
	return (i);
}

void	ft_reverse(char *c)
{
	int		n;
	int		i;
	char	temp;

	n = ft_strlen(c);
	i = 0;
	while (i < n / 2)
	{
		temp = c[i];
		c[i] = c[n - i - 1];
		c[n - i - 1] = temp;
		i++;
	}
}

void	init_ulli(unsigned long long int num, char *c)
{
	int	i;
	int	s;

	i = 0;
	while (num)
	{
		s = num % 16;
		if (s < 0)
			s *= -1;
		if (s > 9)
			c[i] = (char)(55 + s);
		else
			c[i] = (char)(48 + s);
		num /= 16;
		i++;
	}
}

char	*get_16(unsigned long long int num)
{
	char	*c;
	int		n;

	n = get_size(num);
	c = malloc(sizeof(char) * (n + 1));
	if (!c)
		return (NULL);
	ft_bzero(c, n + 1);
	if (num == 0)
		c[0] = '0';
	init_ulli(num, c);
	ft_reverse(c);
	return (c);
}

void	ft_to_lower_case(char *value)
{
	int	i;

	i = 0;
	if (!value)
		return ;
	while (value[i])
	{
		if (value[i] >= 65 && value[i] <= 90)
			value[i] += 32;
		i++;
	}
}
