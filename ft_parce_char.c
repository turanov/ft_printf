#include "ft_printf.h"

void	parce_char(t_data **pData, va_list list)
{
	(*pData)->v = malloc(sizeof(int) * 2);
	if (!(*pData)->v)
		return ;
	(*pData)->v[0] = va_arg(list, int);
	(*pData)->v[1] = '\0';
}
