#include "precision.h"

int handle_precision(char **format, va_list args)
{
    int precision = -1;
    if (**format == '.')
    {
        (*format)++;
        if (isdigit(**format))
        {
            precision = atoi(*format);
            while (isdigit(**format))
                (*format)++;
        }
        else if (**format == '*')
        {
            precision = va_arg(args, int);
            (*format)++;
        }
    }
    return precision;
}
