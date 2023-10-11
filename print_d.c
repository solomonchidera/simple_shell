#include "shell.h"

/**
 * print_d - function to print a int number
 * @d: paramaters
 *
 * Return: the number of characters printed
 * On error, -1 is returned, and errno is set appropriately.
 */

int print_d(va_list d)
{
	int count, n2, num2;
	int n, div, num3;

	n = va_arg(d, int);
	n2 = n;
	count = 0;
	while (n2 != 0)
	{
		n2 = n2 / 10;
		count++;
	}
	div = 1;
	for (num2 = 1 ; num2 < count ; num2++)
	{
		div = div * 10;
	}
	if (n == 0)
	{
		_putchar('0');
		return (1);
	}
	else if (n > 0)
	{
		for (num3 = count + 1 ; num3 > 1 ; num3--)
		{
			_putchar ((n / div) % 10 + '0');
			div = div / 10;
		}
		return (count);
	}
	else
	{
		_putchar ('-');
		for (num3 = count + 1 ; num3 > 1 ; num3--)
		{
			_putchar (-1 * ((n / div) % 10) + '0');
			div = div / 10;
		}
		return (count + 1);
	}
}
