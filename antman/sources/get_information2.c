/*
** EPITECH PROJECT, 2022
** Fundamentalfunctions
** File description:
** my_charcat
*/

#include "./../../includes/library.h"

void quantity_words(t_var *var)
{
    int i = 1;
    var->num_words = 1;
    while (i < var->sizetext)
    {
        if ((isalpha(var->arraytext[i - 1]) != 0 ||
        isdigit(var->arraytext[i - 1]) != 0)
        && (isalpha(var->arraytext[i]) == 0 &&
        isdigit(var->arraytext[i]) == 0))
            var->num_words++;
        i++;
    }
}

int get_lenword(t_var *var, int i)
{
    int len_word = 0;

    while (isalpha(var->arraytext[i]) != 0
    || isdigit(var->arraytext[i]) != 0) {
        len_word++;
        i++;
    }
    return (len_word);
}

char *get_word(t_var *var, int i, int len_word)
{
    char *word = malloc(sizeof(char) * len_word + 10);
    int j = 0;

    my_memset(word, '\0', len_word + 1);
    while (j <= len_word) {
        word[j] = var->arraytext[i];
        j++;
        i++;
    }
    word[j] = '\0';
    return (word);
}

void get_bit_value(t_var *var, t_info_files *file,
t_char_codes *linked, char *prev_value_bit)
{
    if (file->bit != NULL) {
        char *test = my_strdup(prev_value_bit);
        char *test2 = my_strdup(file->bit);
        file->value_bit = malloc(sizeof(char) * (strlen(prev_value_bit)
        + my_strlen(file->bit)) + 1);
        strcpy(file->value_bit, test);
        strcat(file->value_bit, test2);
    } else {
        file->value_bit = prev_value_bit;
    }
    if (file->right != NULL)
        get_bit_value(var, file->right, linked, file->value_bit);
    if (file->left != NULL)
        get_bit_value(var, file->left, linked, file->value_bit);
    else if (file->right == NULL && file->left == NULL) {
        create_new_linkcode(var, file, linked);
    }
}

void repeat_words(t_var *var)
{
    int i = 0;
    int j = 0;
    int counter = 0;

    while (var->array_words[i] != NULL) {
        counter = find_str_array(var, var->array_words[i]);
        if (counter > 1) {
            var->array_characters[var->total_char] =
            my_strdup(var->array_words[i]);
            var->array_num_characters[var->total_char] = counter;
            var->total_char++;
        }
        i++;
    }
    var->array_characters[var->total_char] = NULL;
}
