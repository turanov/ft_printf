#include "ft_printf.h"

int	print_value_r_helper(t_data **d, int cnt, int i)
{
	if ((*d)->p_s == '#' && (*d)->tp == 'x'
		&& (*d)->v[0] != '0' && (*d)->f == '0')
	{
		(*d)->p_s = -1;
		cnt += ft_putstr_fd("0x", 1);
	}
	if ((*d)->p_s == '#' && (*d)->tp == 'X'
		&& (*d)->v[0] != '0' && (*d)->f == '0')
	{
		(*d)->p_s = -1;
		cnt += ft_putstr_fd("0X", 1);
	}
	while (i < (*d)->width)
	{
		if ((*d)->f == '0')
			i += ft_putchar_fd('0', 1);
		else
			i += ft_putchar_fd(' ', 1);
	}
	return (i + cnt);
}

int	print_value_r(t_data **data, int sign, int len)
{
	int	cnt;

	cnt = 0;
	if ((*data)->precision == -1 && (*data)->f == '0' && sign == 1 )
		cnt += ft_putchar_fd('-', 1);
	if ((*data)->width >ft_max((*data)->precision, len))
	{
		(*data)->width -= ft_max(len, (*data)->precision);
		if ((*data)->p_s != -1 && (*data)->p_s != '#')
			(*data)->width--;
		if ((*data)->p_s != -1 && (*data)->p_s != '#' && (*data)->f == '0')
		{
			cnt += ft_putchar_fd((*data)->p_s, 1);
			(*data)->p_s = -1;
		}
		cnt += print_value_r_helper(data, 0, 0);
	}
	return (cnt);
}

int	print_value_c(t_data **data, int sign, int len, int cnt)
{
	int	i;

	i = 0;
	if (((*data)->precision != -1 || (*data)->f != '0') && sign == 1 )
		cnt += ft_putchar_fd('-', 1);
	if ((*data)->tp == 'p' || ((*data)->p_s == '#'
			&& (*data)->tp == 'x' && (*data)->v[0] != '0'))
		cnt += ft_putstr_fd("0x", 1);
	if (((*data)->p_s == '#' && (*data)->tp == 'X' && (*data)->v[0] != '0'))
		cnt += ft_putstr_fd("0X", 1);
	if ((*data)->p_s != -1 && (*data)->p_s != '#')
		cnt += ft_putchar_fd((*data)->p_s, 1);
	if ((*data)->precision != -1 && (*data)->precision > len)
	{
		while (i < (*data)->precision - len)
			i += ft_putchar_fd('0', 1);
	}
	if ((*data)->v[0] == '0' && (*data)->precision != 0 )
		cnt += ft_putchar_fd('0', 1);
	if ((*data)->v[0] != '0')
		cnt += ft_putstr_fd((*data)->v + sign, 1);
	return (cnt + i);
}

int	print_value_l(t_data **data, int len)
{
	int	cnt;

	cnt = 0;
	if ((*data)->width > ft_max((*data)->precision, len))
	{
		(*data)->width -= ft_max((*data)->precision, len);
		if ((*data)->p_s != -1 && (*data)->p_s != '#')
			(*data)->width--;
		while (cnt < (*data)->width)
			cnt += ft_putchar_fd(' ', 1);
	}
	return (cnt);
}

int	print_value(t_data *data, int cnt, int sign, int len)
{
	if (data->v[0] == '-')
	{
		sign = 1;
		len -= 1;
		data->width -= 1;
		data->p_s = -1;
	}
	if (data->v[0] == '0' && data->precision == 0)
		len -= 1;
	if (data->tp == 'p' || (data->p_s == '#'
			&& (data->tp == 'x' || data->tp == 'X') && data->v[0] != '0'))
		data->width -= 2;
	if (data->precision != -1)
		if (data->f == '0')
			data->f = -1;
	if (data->f != '-')
		cnt += print_value_r(&data, sign, len);
	cnt += print_value_c(&data, sign, len, 0);
	if (data->f == '-')
		cnt += print_value_l(&data, len);
	return (cnt);
}
