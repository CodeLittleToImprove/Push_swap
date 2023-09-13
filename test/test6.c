#include <stdio.h>
#include <limits.h>

long long    ft_atoll(const char *nptr)
{
    long long        nbr;
    int        sign;

    nbr = 0;
    sign = 1;
    while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
        nptr++;
    if (*nptr == '-')
        sign = -1;
    if (*nptr == '+' || *nptr == '-')
        nptr++;
    while (*nptr >= '0' && *nptr <= '9')
    {
        if ((nbr > LLONG_MAX / 10) || (nbr == LLONG_MAX / 10 ))
        {
            if (sign == -1)
                return (LLONG_MIN);
            else
            {
                printf("else if\n");
                return (LLONG_MAX);
            }

        }
        nbr = nbr * 10 + *nptr - '0';
        printf("%lld\n", nbr);
        nptr++;
    }
    return (sign * nbr);
}
int main() {
    const char *str1 = "9223372036854775809";  // A very large number

    long long num1 = ft_atoll(str1);

    printf("num1 = %lld\n", num1);

    return 0;
}