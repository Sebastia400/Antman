/*
** EPITECH PROJECT, 2022
** Fundamentalfunctions
** File description:
** my_charcat
*/

#include "./../../includes/library.h"

t_var *init_var(void)
{
    t_var *var = malloc(sizeof(t_var));
    var->array_num_characters = NULL;
    var->arraytext = NULL;
    var->filepath = NULL;
    var->bit_concate = NULL;
    var->prev_value_bit = NULL;
    var->array_characters = NULL;
    var->array_words = NULL;
    return var;
}
