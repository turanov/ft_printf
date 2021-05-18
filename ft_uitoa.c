#include "ft_printf.h"

static int	ft_schet(unsigned long long int l);
static void	ft_algoritm(char *s, unsigned long long int n, int len);

char	*ft_uitoa(unsigned long long int n)
{
	int						j;
	unsigned long long int	nb;
	char					*str;

	nb = n;
	if (nb < 0)
		nb = nb * (-1);
	j = ft_schet(nb);
	str = (char *)malloc(j + 1);
	if (!str)
		return (NULL);
	ft_algoritm(str, nb, j);
	str[j] = '\0';
	return (str);
}

int	ft_schet(unsigned long long int l)
{
	int	count;

	count = 0;
	if (l == 0)
		return (1);
	while (l != 0)
	{
		l = l / 10;
		count++;
	}
	return (count);
}

void	ft_algoritm(char *s, unsigned long long int n, int len)
{
	len--;
	if (n == 0)
		s[len] = '0';
	while (len >= 0)
	{
		s[len--] = n % 10 + 48;
		n /= 10;
	}
}
