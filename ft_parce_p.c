#include "ft_printf.h"

void	parce_p(t_data **pData, va_list list)
{
	(*pData)->v = get_16(va_arg(list, unsigned long long int));
	ft_to_lower_case((*pData)->v);
}
