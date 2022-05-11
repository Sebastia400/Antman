/*
** EPITECH PROJECT, 2022
** Fundamentalfunctions
** File description:
** my_charcat
*/

#include "./../../includes/library.h"

char *char_to_code(char letter)
{
    int value = 128;
    int char_value = (int)letter;
    char *tmp = malloc(sizeof(char) * 8 + 1);

    for (int i = 0; i != 8; i++) {
        if (char_value > value) {
            char_value -= value;
            tmp[i] = '1';
        } else
            tmp[i] = '0';
        value = value / 2;
    }
    tmp[8] = '\0';
    return (tmp);
}

void un_char_str(t_var2 *var, char *str)
{
    int value = 0;
    int bite = 64;
    char *result = malloc(sizeof(char) * my_strlen(str) * 8 + 1);

    memset(result, '\0', my_strlen(str) * 8 + 1);
    for (int i = 0; str[i] != '\0'; i++) {
        value = (int)str[i];
        result = strcat(result, char_to_code(str[i]));
        i++;
    }
    var->compressed_binari = result;
}

void get_dictionary2(t_var2 *var)
{
    int i = 0;
    int j = 0;
    int n = 0;
    int x = 0;
    char *word = NULL;

    var->word = malloc(sizeof(char *) * my_strlen(var->dic));
    var->code = malloc(sizeof(char *) * my_strlen(var->dic));
    while (var->dic[i] != '\0') {
        word = malloc(sizeof(char) * 100);
        var->code[n] = malloc(sizeof(char) * 100);
        memset(word, '\0', 100);
        memset(var->code[n], '\0', 100);
        while (var->dic[i] != ' ' || j < 0 && var->dic[i] == '\0') {
            word[j++] = var->dic[i++];
        }
        var->word[n] = word;
        i += 1;
        j = 0;
        while (var->dic[i] != '\n' && i < var->total_char) {
            strcat(var->code[n], char_to_code(var->dic[i++]));
        }
        i++;
        n++;
    }
    var->word[n] = NULL;
    var->code[n] = NULL;
}

void get_dictionary(t_var2 *var)
{
    int i = 0;
    int n = 0;

    var->dic = malloc(sizeof(char) * my_strlen(var->arraytext));
    var->message = malloc(sizeof(char) * my_strlen(var->arraytext));
    memset(var->dic, '\0', my_strlen(var->arraytext));
    memset(var->message, '\0', my_strlen(var->arraytext));
    while (var->arraytext[i] != '\n' || var->arraytext[i + 1] != '\n') {
        var->dic[i] = var->arraytext[i];
        var->total_char = i;
        i++;
    }
    while (var->arraytext[i] != '\0') {
        var->message[n] = var->arraytext[i];
        n++;
        i++;
    }
    get_dictionary2(var);
}
