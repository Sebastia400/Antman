/*
** EPITECH PROJECT, 2022
** Fundamentalfunctions
** File description:
** my_charcat
*/

#include "./../../includes/library.h"

void create_new(t_var *var, t_info_files *file)
{
    t_info_files *tmp = file;

    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = ini_new_info_files(var);
}

void create_new_tree(t_var *var, t_info_files *file)
{
    t_info_files *tmp = file;
    t_info_files *first = tmp;
    t_info_files *second = tmp->next;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = ini_new_info_files_tree(var, first, second);
}

void create_tree(t_var *var, t_info_files *file)
{
    int i = var->total_char;
    int j = 0;
    t_info_files *tmp = file->next;

    while (i > 1) {
        create_new_tree(var, tmp);
        sort_date_linked(tmp);
        j = 0;
        while (j < 2) {
            tmp = tmp->next;
            j++;
        }
        *file = *file->next;
        i--;
    }
    *file = *file->next;
}

void create_new_linkcode(t_var *var, t_info_files *file, t_char_codes *linked)
{
    t_char_codes *tmp = linked;

    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = ini_new_char_files(var, file);
}
