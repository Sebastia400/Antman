/*
** EPITECH PROJECT, 2022
** Fundamentalfunctions
** File description:
** my_charcat
*/

#include "./../../includes/library.h"

void write_key2(char *string_key)
{
    if (string_key[0] == '\0')
        write(1, "000", 3);
    else if (string_key[0] == '\r')
        write(1, "111", 3);
    else if (string_key[0] == '\n')
        write(1, "222", 3);
    else
        write(1, string_key, strlen(string_key));
}

void write_key(t_var *var, t_char_codes *linked)
{
    t_char_codes *tmp = linked->next;
    char *string_key = malloc(sizeof(char) * strlen(tmp->character));

    memset(string_key, '\0', strlen(tmp->character));
    while (tmp != NULL) {
        string_key = my_strdup(tmp->character);
        write_key2(string_key);
        string_key = NULL;
        string_key = my_strdup(tmp->code);
        write(1, " ", 1);
        get_bits(var, string_key);
        write(1, "\n", 1);
        string_key = NULL;
        tmp = tmp->next;
    }
    write(1, "\n", 1);
    free(string_key);
}

char *get_eightbits(t_var *var, char *string_codes)
{
    char *tmp;
    int i;
    int j;

    while (strlen(string_codes) >= 8) {
        tmp = strdup(string_codes);
        tmp[8] = '\0';
        get_bits(var, tmp);
        i = 8;
        j = 0;
        while (string_codes[i] != '\0') {
            string_codes[j] = string_codes[i];
            j++;
            i++;
        }
        string_codes[j] = '\0';
    }
    return (string_codes);
}

void bitwise_print(t_var *var, t_char_codes *linked)
{
    t_char_codes *tmp = linked->next;
    int i = 0;
    int lenword = get_lenword(var, i);
    char *word = get_word(var, i, lenword-1);
    char *code = get_code(var, tmp, word);
    char *string_codes = malloc(sizeof(char) * strlen(code) + 1);

    my_memset(string_codes, '\0', strlen(code));
    while (var->arraytext[i] != '\0') {
        lenword = get_lenword(var, i);
        word = get_word(var, i, lenword-1);
        code = get_code(var, tmp, word);
        if (my_strcmp(code, "-1") != 0)
            i += lenword;
        else
            code = get_code_char(var, tmp, var->arraytext[i++]);
        string_codes = my_strcat(string_codes, code);
        if (strlen(string_codes) >= 8)
            string_codes = strdup(get_eightbits(var, string_codes));
    }
    string_codes = my_strcat(string_codes, "\0");
    get_bits(var, string_codes);
    free (word);
    free(string_codes);
}
