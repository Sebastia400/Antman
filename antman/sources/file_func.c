/*
** EPITECH PROJECT, 2022
** Fundamentalfunctions
** File description:
** my_charcat
*/

#include "./../../includes/library.h"

int fs_open_file(char const *filepath)
{
    if (open(filepath, O_RDONLY) != -1)
        return (0);
    else
        return (84);
}

void errase_file(t_var *var)
{
    write(1, "", 0);
}
