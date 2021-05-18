#include "ft_printf.h"

t_data	*new_data(void)
{
	t_data	*data;

	data = (t_data *) malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->tp = -1;
	data->v = NULL;
	data->width = -1;
	data->precision = -1;
	data->f = -1;
	data->lon = -1;
	data->printed = -1;
	data->p_s = -1;
	return (data);
}
