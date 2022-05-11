/*
** EPITECH PROJECT, 2022
** Fundamentalfunctions
** File description:
** my_getnbr
*/

#include "./../../../includes/library.h"

int my_getnbr(char const *str)
{
    int i = 0;
    int neg = 1;
    int nb = 0;

    while (str[i] != '\0') {
        if (nb > INT_MAX || nb < INT_MIN) {
            return (0);
        } if (str[i] == '-') {
            neg *= -1;
        } if (str[i] >= '0' && str[i] <= '9') {
            nb *= 10;
            nb += str[i] - 48;
        } if (nb > 0 && (str[i] < '0' || str[i] > '9')) {
            return (nb * neg);
        }
        i++;
    }
    return (nb * neg);
}
