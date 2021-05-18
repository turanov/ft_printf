#include "ft_printf.h"

void	parce_int(t_data **pData, va_list list)
{
	(*pData)->v = ft_itoa(va_arg(list, int));
}

void	parce_long_int(t_data **pData, va_list list)
{
	(*pData)->v = ft_itoa(va_arg(list, long int));
}

void	parce_long_long_int(t_data **pData, va_list list)
{
	(*pData)->v = ft_itoa(va_arg(list, long long int));
}

void	parce_short_int(t_data **pData, va_list list)
{
	(*pData)->v = ft_itoa((short int)va_arg(list, int));
}

void	parce_short_short_int(t_data **pData, va_list list)
{
	(*pData)->v = ft_itoa((char)va_arg(list, int));
}
