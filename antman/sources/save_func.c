/*
** EPITECH PROJECT, 2022
** Fundamentalfunctions
** File description:
** my_charcat
*/

#include "./../../includes/library.h"

void save_word_ext(t_var *var, int i, int k)
{
    int ini = 0;
    int j = 0;

    if (var->len_word > 1) {
        var->array_words[j] = calloc(var->len_word * 2, sizeof(char));
        ini = i - var->len_word;
        while (k < var->len_word) {
            var->array_words[j][k] = var->arraytext[ini];
            ini++;
            k++;
        }
        var->array_words[j][k] = '\0';
        j++;
    }
}

void save_word(t_var *var)
{
    int i = 0;
    int k = 0;

    var->len_word = 0;
    var->array_words = calloc(var->num_words * 2, sizeof(char *));
    while (i < var->sizetext || var->len_word > 1) {
        k = 0;
        if (isalpha(var->arraytext[i]) != 0 || isdigit(var->arraytext[i]) != 0)
            var->len_word++;
        else {
            save_word_ext(var, i, k);
            var->len_word = 0;
        }
        i++;
    }
    var->array_words[i] = NULL;
}

void save_word2(t_var *var, int i, int len_word)
{
    int ini = 0;
    int j = 0;
    int k = 0;

    if (len_word > 1) {
        var->array_words[j] = my_calloc(len_word * 2 + 10, sizeof(char));
        ini = i - len_word;
        while (k < len_word) {
            var->array_words[j][k] = var->arraytext[ini];
            ini++;
            k++;
        }
        var->array_words[j][k] = '\0';
        j++;
    }
}

void save_charcters(t_var *var)
{
    int i = 0;

    var->total_char = 0;
    var->array_characters = my_calloc(var->sizetext + 1, sizeof(char *));
    var->array_num_characters = malloc(sizeof(int) * var->sizetext + 1);
    var->array_characters[i] = NULL;
    while (i < var->sizetext) {
        if (find_index_array(var, var->arraytext[i]) == -1) {
            var->array_characters[var->total_char] = my_calloc(2, sizeof(char));
            var->array_characters[var->total_char][0] = var->arraytext[i];
            var->array_characters[var->total_char][1] = '\0';
            var->array_num_characters[var->total_char] = 1;
            var->total_char++;
        } else
            var->array_num_characters[find_index_array(var,
            var->arraytext[i])]++;
        i++;
    }
    var->array_characters[var->total_char + 1] = NULL;
}

void save_nodes(t_var *var, t_info_files *file)
{
    int i = 0;

    var->point = 0;
    while (var->point < var->total_char) {
        create_new(var, file);
        var->point++;
    }
}
