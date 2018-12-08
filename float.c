#include <stdio.h>
#include <stdlib.h>

long double	ft_modulus(long double a, long double b)
{
	long long result;
	
	result = (long long)( a / b );
	return (a - (long double)(result) * b);
}

unsigned int	ft_len(long double n)
{
	long long	i;
	long double	d;
	long double	t;
	unsigned int	len;

	i = (long long)n;
	len = 0;
	d = 1;
	t = 10;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (i > 0)
	{
		i = i / 10;
		len++;
	}
	len++;
	while ((int)(ft_modulus(n, d) * t) > 0)
	{
		len++;
		d = d / 10;
		t = t * 10;
	}
	return (len);
}

int	ft_len_int(long long n)
{
	int len;

	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa_float(long double n)
{
	long double	i;
	long double	j;
	char		*str;
	long long	l;
	long long	b;
	int		int_len;

	i = 1;
	j = 10;
	l = 0;
	if (!(str = (char*)malloc(sizeof(char) * (ft_len(n) + 1))))
		return (NULL);
	if (n == 0)
		return ("0");
	int_len = ft_len_int((long long)n) - 1;
	if (n < 0)
	{
		str[l] = '-';
		l++;
		n = -n;
	}
	b = (long long)n;
	while (b > 0)
	{
		str[int_len--] = (b % 10) + '0';
		b = b / 10;
		l++;
	}
	str[l++] = '.';
	while ((int)(ft_modulus(n, i) * j) > 0)
	{
		str[l] = (int)(ft_modulus(n, i) * j) + '0';
		i = i / 10;
		j = j * 10;
		l++;
	}
	str[l] = '\0';
	return (str);
}

int main(void)
{
	long double i = -991.99999356789;
	printf("%s\n", ft_itoa_float(i));
}
