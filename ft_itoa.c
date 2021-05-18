#include "ft_printf.h"

int		ft_schet(long long int l);

void	ft_algoritm(char *s, long long int n,
			long long int len, long long int kk);

char	*ft_itoa(long long int n)
{
	long long int		j;
	long long int		i;
	long long int		nb;
	char				*str;

	nb = n;
	if (nb < 0)
		nb = nb * (-1);
	j = ft_schet(nb);
	if (n < 0)
		j++;
	str = (char *)malloc(j + 1);
	if (!str)
		return (NULL);
	i = 0;
	if (n < 0)
		str[i++] = '-';
	ft_algoritm(str + i, nb, j, n);
	str[j] = '\0';
	return (str);
}

int	ft_schet(long long int l)
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

int	mod(int m)
{
	if (m < 0)
		m *= -1;
	return (m);
}

void	ft_algoritm(char *s, long long n, long long len, long long kk)
{
	len--;
	if (n == 0)
		s[len] = '0';
	if (kk > 0)
	{
		while (len >= 0)
		{
			s[len--] = mod(n % 10) + 48;
			n /= 10;
		}
	}
	else
	{
		while (len--)
		{
			s[len] = mod(n % 10) + 48;
			n /= 10;
		}
	}
}
