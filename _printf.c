#include "main.h"
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * _printf - prints all types of variables
 * own version of built-in printf function
 * @format: list types of arguments
 * Return: number characters printed
 */
void _printf(const char *format, ...)
{
	int i, num_args = strlen(format), num_chars = 0;

	va_list args_list;
	va_start(args_list, format);
	putchar('0');
	while (*format && format[i])
	{
		if (format[i] == '%')
		{
		putchar('1');
			switch (format[i])
			{
			case 'c':
			{
				char c = va_arg(args_list, int);
				putchar(c);
				num_chars++;
				break;
			}
			case 's':
			{
				const char *s = va_arg(args_list, char *);
				while (*s)
					putchar(*s++);
				num_chars++;
				break;
			}
			case 'd':
			{
				double d = va_arg(args_list, int);
				putchar(d);
				num_chars++;
				break;
			}
			case 'i':
			{
				putchar(va_arg(args_list, int));
				num_chars++;
				break;
			}
			}
		}	
		format++;
	}
//	return (num_chars);
}

int main()
{
//	void *ptr_to_main = (void*) main;
	_printf("print a character: %c\n", 'H');
	_printf("print a string: %s\n", "Hello World");
	_printf("print an int: %c\n", 5);
	_printf("print a neg int: %c\n", -5);

	return (0);
}
