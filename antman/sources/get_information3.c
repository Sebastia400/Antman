/*
** EPITECH PROJECT, 2022
** Fundamentalfunctions
** File description:
** my_charcat
*/

#include "./../../includes/library.h"

char *get_code(t_var *var, t_char_codes *linked, char *word)
{
    t_char_codes *tmp = linked;

    while (tmp != NULL) {
        if (my_strcmp(word, tmp->character) == 0)
            return (tmp->code);
        tmp = tmp->next;
    }
    return ("-1");
}
