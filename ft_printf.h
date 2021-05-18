#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
typedef struct s_data
{
	char	tp;
	char	*v;
	int		width;
	int		precision;
	char	f;
	char	lon;
	int		printed;
	char	p_s;
}			t_data;

t_data	*new_data(void);
char	*get_16(unsigned long long int num);
char	*ft_strdup(char *src);
char	*ft_itoa(long long int n);
char	*ft_uitoa(unsigned long long int n);
void	ft_bzero(void *s, size_t n);
void	get_precision(t_data **pData, char **pString, va_list list);
void	get_width(t_data **pData, char **pString, va_list list);
void	get_flags(t_data **pData, char **pString);
void	ft_to_lower_case(char *value);
void	ft_reverse(char *c);
void	init_ulli(unsigned long long int num, char *c);
int		ft_strlen(char *str);
int		ft_putstr_fd(char *s, int fd);
int		ft_putchar_fd(char c, int fd);
int		ft_printf(const char *s, ...);
int		get_type(t_data **pData, char **pString);
int		get_size(unsigned long long int num);
int		get_type_and_value(t_data **pData, char **pString, va_list list);
int		print_value_r(t_data **data, int sign, int len);
int		print_value_c(t_data **data, int sign, int len, int cnt);
int		print_value_l(t_data **data, int len);
int		print_value(t_data *data, int cnt, int sign, int len);
int		ftPrintData(t_data *data);
int		print_char(t_data *data);
int		print_string(t_data *data, int i, int cnt);
int		ft_put_n(char c, int n);
int		ft_max(int precision, int num);
int		is_char_in_str(char symbol, char *str);
int		get_type_and_value(t_data **pData, char **pString, va_list list);
void	get_value_from_num(t_data **pData, va_list list);
void	get_value_from_int(t_data **pData, va_list list);
void	get_value_from_short_short(t_data **pData, va_list list);
void	get_value_from_short(t_data **pData, va_list list);
void	get_value_from_long_long(t_data **pData, va_list list);
void	get_value_from_long(t_data **pData, va_list list);
void	parce_char(t_data **data, va_list list);
void	parce_int(t_data **pData, va_list list);
void	parce_long_int(t_data **pData, va_list list);
void	parce_long_long_int(t_data **pData, va_list list);
void	parce_usigned_int(t_data **pData, va_list list);
void	parce_unsigned_long_int(t_data **pData, va_list list);
void	parce_unsigned_long_long_int(t_data **pData, va_list list);
void	parce_p(t_data **pData, va_list list);
void	parce_int_x(t_data **pData, va_list list);
void	parce_long_int_x(t_data **pData, va_list list);
void	parce_long_long_int_x(t_data **pData, va_list list);
void	parce_int_n(t_data **pData, va_list list);
void	parce_long_int_n(t_data **pData, va_list list);
void	parce_long_long_int_n(t_data **pData, va_list list);
void	parce_short_int(t_data **pData, va_list list);
void	parce_short_short_int(t_data **pData, va_list list);
void	parce_short_int_n(t_data **pData, va_list list);
void	parce_short_short_int_n(t_data **pData, va_list list);
void	parce_unsigned_short_int(t_data **pData, va_list list);
void	parce_unsigned_short_short_int(t_data **pData, va_list list);
void	parce_short_int_x(t_data **pData, va_list list);
void	parce_short_short_int_x(t_data **pData, va_list list);

#endif
