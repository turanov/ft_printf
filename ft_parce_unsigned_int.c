#include "ft_printf.h"

void	parce_usigned_int(t_data **pData, va_list list)
{
	(*pData)->v = ft_itoa(va_arg(list, unsigned int));
}

void	parce_unsigned_long_int(t_data **pData, va_list list)
{
	(*pData)->v = ft_uitoa(va_arg(list, unsigned long int));
}

void	parce_unsigned_long_long_int(t_data **pData, va_list list)
{
	(*pData)->v = ft_uitoa(va_arg(list, unsigned long long int));
}

void	parce_unsigned_short_int(t_data **pData, va_list list)
{
	(*pData)->v = ft_uitoa((unsigned short int)va_arg(list, int));
}

void	parce_unsigned_short_short_int(t_data **pData, va_list list)
{
	(*pData)->v = ft_uitoa((unsigned char)va_arg(list, int));
}
