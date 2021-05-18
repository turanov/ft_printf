#include "ft_printf.h"

void	parce_int_n(t_data **pData, va_list list)
{
	int	*n;

	n = va_arg(list, int *);
	*n = (*pData)->printed;
}

void	parce_long_int_n(t_data **pData, va_list list)
{
	long int	*n;

	n = va_arg(list, long int *);
	*n = (*pData)->printed;
}

void	parce_long_long_int_n(t_data **pData, va_list list)
{
	long long int	*n;

	n = va_arg(list, long long int *);
	*n = (*pData)->printed;
}

void	parce_short_int_n(t_data **pData, va_list list)
{
	short int	*n;

	n = va_arg(list, short int *);
	*n = (*pData)->printed;
}

void	parce_short_short_int_n(t_data **pData, va_list list)
{
	char	*n;

	n = va_arg(list, char *);
	*n = (*pData)->printed;
}
