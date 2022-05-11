/*
** EPITECH PROJECT, 2022
** Fundamentalfunctions
** File description:
** my_charcat
*/

#include "./../../includes/library.h"

void free_linked(t_info_files *file, t_char_codes *linked)
{
    while (file != NULL)
    {
        free(file->bit);
        free(file->right);
        free(file->left);
        file = file->next;
    }
    free(file);
    free(linked);
}

void free_words(t_var *var)
{
    int i = 0;
    while (i < var->total_char)
    {
        free(var->array_words[i]);
        i++;
    }
    free(var->array_words);
}

void free_struct(t_var *var)
{
    int i = 0;
    while (i < var->sizetext)
    {
        free(var->array_characters[i]);
        i++;
    }
    free(var->array_characters);
    free(var->prev_value_bit);
    free(var->bit_concate);
    free(var->filepath);
    free(var);
}
