#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - Custom printf function with basic format specifiers.
 * @format: Format string with specifiers.
 *
 * Return: Number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++; /* Move to the next character after '%' */
            switch (*format)
            {
            case 'c':
                count += putchar(va_arg(args, int));
                break;
            case 's':
                count += printf("%s", va_arg(args, char *));
                break;
            case '%':
                count += putchar('%');
                break;
            default:
                putchar('%');
                putchar(*format);
                count += 2;
                break;
            }
        }
        else
        {
            putchar(*format);
            count++;
        }
        format++;
    }

    va_end(args);

    return count;
}

/**
 * main - Example usage of _printf function.
 *
 * Return: Always 0.
 */
int main(void)
{
    int count;

    count = _printf("This is a simple _printf function.\n");
    printf("Number of characters printed: %d\n", count);

    count = _printf("Character: %c, String: %s, Percent: %%\n", 'A', "Hello, World!");
    printf("Number of characters printed: %d\n", count);

    return 0;
}
