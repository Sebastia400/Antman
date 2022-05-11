/*
** EPITECH PROJECT, 2022
** Fundamentalfunctions
** File description:
** my_charcat
*/

#include "./../../includes/library.h"

t_info_files *ini_new_info_files(t_var *var)
{
    t_info_files *file = init_file();

    file->character = my_calloc(my_strlen(var->array_characters[var->point]) +
    1, sizeof(char));
    file->character = var->array_characters[var->point];
    file->quantity = var->array_num_characters[var->point];
    file->value_bit = malloc(sizeof(char) * var->total_char / 2 + 1);
    file->right = NULL;
    file->left = NULL;
    file->next = NULL;
    return file;
}

t_char_codes *ini_new_char_files(t_var *var, t_info_files *file)
{
    t_char_codes *temp = malloc(sizeof(t_char_codes));

    temp->character = file->character;
    temp->code = file->value_bit;
    temp->next = NULL;
    return temp;
}

t_info_files *ini_new_info_files_tree(t_var *var, t_info_files *first,
t_info_files *second)
{
    t_info_files *file = malloc(sizeof(t_info_files));
    int suma = first->quantity + second->quantity;

    file->character = my_return_char(suma);
    file->value_bit = NULL;
    file->quantity = suma;
    file->right = second;
    file->right->bit = my_strdup("1");
    file->left = first;
    file->left->bit =  my_strdup("0");
    file->next = NULL;
    return file;
}

t_info_files *init_file(void) {
    t_info_files *res = malloc(sizeof(t_info_files));
    res->character = NULL;
    res->next = NULL;
    res->bit = NULL;
    res->value_bit = NULL;
    res->right = NULL;
    res->left = NULL;
    return res;
}

t_char_codes *init_char(void) {
    t_char_codes *res = malloc(sizeof(t_char_codes));
    res->character = NULL;
    res->code = NULL;
    res->next = NULL;
    return res;
}
