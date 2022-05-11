/*
** EPITECH PROJECT, 2022
** Fundamentalfunctions
** File description:
** my_charcat
*/

#include "./../../includes/library.h"

void save_text(t_var *var, int fd)
{
    int i = 0;
    int size = 0;
    var->sizetext = 0;
    struct stat buf;
    long max_size = 0;
    stat(var->filepath, &buf);
    var->sizetext = buf.st_size;
    var->arraytext = malloc(sizeof(char) * var->sizetext + 1);
    my_memset(var->arraytext, '\0', var->sizetext + 1);
    read(fd, var->arraytext, var->sizetext);
}

void func_save_temp(t_info_files *save_tmp, t_info_files *link)
{
    *save_tmp = *link;
    save_tmp->next = NULL;
}

void save_on_pointer(t_info_files *i, t_info_files *temp)
{
    t_info_files *next_ptr = i->next;

    *i = *temp;
    i->next = next_ptr;
}
