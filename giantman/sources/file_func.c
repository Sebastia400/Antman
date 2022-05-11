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
    int fd = open(var->filepath, O_WRONLY | O_TRUNC);

    write(fd, "", 0);
    close(fd);
}
