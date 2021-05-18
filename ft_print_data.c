#include "ft_printf.h"

int	ftPrintData(t_data *data)
{
	int	cnt;

	cnt = 0;
	if (data->tp == 'n')
		return (cnt);
	if (data->tp == 'c')
		cnt += print_char(data);
	else if (data->tp == 's')
		cnt += print_string(data, 0, 0);
	else
		cnt += print_value(data, 0, 0, ft_strlen(data->v));
	return (cnt);
}

int	print_char(t_data *data)
{
	int	cnt;

	cnt = 0;
	data->width -= 1;
	if (data->f != '-')
	{
		if (data->f == '0')
			cnt += ft_put_n('0', data->width);
		else
			cnt += ft_put_n(' ', data->width);
	}
	cnt += ft_putchar_fd(data->v[0], 1);
	if (data->f == '-')
		cnt += ft_put_n(' ', data->width);
	return (cnt);
}

int	print_string_helper(t_data **data)
{
	int	cnt;

	cnt = 0;
	(*data)->width -= (*data)->precision;
	if ((*data)->f == '0')
		cnt += ft_put_n('0', (*data)->width);
	else
		cnt += ft_put_n(' ', (*data)->width);
	return (cnt);
}

int	print_string(t_data *data, int i, int cnt)
{
	int	len;

	if (data->v == NULL)
		data->v = ft_strdup("(null)");
	if (data->v == NULL)
		return (-1);
	len = ft_strlen(data->v);
	if (data->precision < 0)
		data->precision = len;
	if (data->precision > len)
		data->precision = len;
	if (data->f != '-')
		cnt += print_string_helper(&data);
	while (data->v[i] && i < data->precision)
		cnt += ft_putchar_fd(data->v[i++], 1);
	if (data->f == '-')
		cnt += ft_put_n(' ', data->width - data->precision);
	return (cnt);
}
