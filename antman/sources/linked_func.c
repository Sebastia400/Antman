/*
** EPITECH PROJECT, 2022
** Fundamentalfunctions
** File description:
** my_charcat
*/

#include "./../../includes/library.h"

void sort_date_linked(t_info_files *linked)
{
    t_info_files *i = linked->next;
    t_info_files *j = linked->next;
    t_info_files *save_tmp = malloc(sizeof(t_info_files));

    while (i != NULL) {
        j = i;
        while (j != NULL) {
            if (i->quantity > j->quantity) {
                func_save_temp(save_tmp, i);
                save_on_pointer(i, j);
                save_on_pointer(j, save_tmp);
            }
            j = j->next;
        }
        i = i->next;
    }
    free(save_tmp);
}
