/*
** EPITECH PROJECT, 2022
** Fundamentalfunctions
** File description:
** my_charcat
*/

#include "./../../includes/library.h"

char *get_code_char(t_var *var, t_char_codes *linked, char word)
{
    t_char_codes *tmp = linked;
    while (tmp != NULL) {
        if (word == tmp->character[0])
            return (tmp->code);
        tmp = tmp->next;
    }
    return ("-1");
}

char get_byte(char *byte)
{
    int i = 0;
    unsigned char code;
    while (byte[i] != '\0') {
        if (byte[i] == '1') {
            code <<= 1;
            code |= 1;
        } else {
            code <<= 1;
        }
        i++;
    }
    return (code);
}

char *write_bits(t_var *var, char *str_code)
{
    int i = strlen(str_code);
    int j = 7;
    char *finalbyte = malloc(sizeof(char) * 9);

    my_memset(finalbyte, '0', 9);
    while (i > 0) {
        finalbyte[j] = str_code[i - 1];
        j--;
        i--;
    }
    finalbyte[8] = '\0';
    return (finalbyte);
}

void get_bits2(t_var *var, unsigned char code)
{
    if (code == '\0')
        write(1, "000", 3);
    else if (code == '\r')
        write(1, "111", 3);
    else if (code == '\n')
        write(1, "222", 3);
    else
        write(1, &code, sizeof(unsigned char));
}

void get_bits(t_var *var, char *str_code)
{
    char *byte = malloc(sizeof(char) * 19);
    char *temp = NULL;
    int i = 0;
    int j = 0;
    unsigned char code = '\0';

    my_memset(byte, '\0', 19);
    while (str_code[i] != '\0') {
        byte[j] = str_code[i];
        if (j == 7 || str_code[i + 1] == '\0') {
            temp = write_bits(var, byte);
            code = get_byte(temp);
            get_bits2(var, code);
            my_memset(byte, '\0', 19);
            j = 0;
        } else
            j++;
        i++;
    }
    free(byte);
}
