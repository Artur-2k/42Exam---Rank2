#include <stdarg.h>
#include <unistd.h>

int     is_whitespace(char c)
{
    if (c == ' ' || c == '\n' || c == '\t' || c == '\r' || c == '\f' || c == '\v')
        return (1);
    return (0);
}

void    print_first_word(char *str)
{
    while (*str && is_whitespace(*str))
        str++;
    if (!*str)
        return ;
    while (*str && !is_whitespace(*str))
    {
        write(1, str, 1);
        str++;
    }
    write(1, "\n", 1);
    return ;
}

int     main(int ac, char **av)
{
    if (ac != 2 && (!av[1] || !av[1][0]))
    {
        write(1, "\n", 1);
        return (0);
    }
    print_first_word(av[1]);
    return 0;
}
