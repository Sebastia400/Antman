/*
** EPITECH PROJECT, 2022
** Fundamentalfunctions
** File description:
** Extra_functions
*/

#include "./../../../includes/library.h"

void revstr(char *str1)
{
    int i, len, temp;
    len = my_strlen(str1);

    for (i = 0; i < len/2; i++)
    {
        temp = str1[i];
        str1[i] = str1[len - i - 1];
        str1[len - i - 1] = temp;
    }
}
