/*
** EPITECH PROJECT, 2021
** victor header
** File description:
** fgfghgf
*/

#ifndef STRUCTS_H_
    #define STRUCTS_H_
    #include <time.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>

    typedef struct s_var {
        int sizetext;
        int num_words;
        int total_char;
        int point;
        int fd;
        int fd2;
        int nbr_char_dic;
        int first;
        int len_word;
        int *array_num_characters;
        char *arraytext;
        char *filepath;
        char *bit_concate;
        char *prev_value_bit;
        char **array_characters;
        char **array_words;
    } t_var;

    typedef struct s_var2 {
        int fd;
        char *filepath;
        char *arraytext;
        char *dic;
        char *message;
        char **word;
        char **code;
        char *compressed_binari;
        int total_char;
    } t_var2;

    typedef struct s_info_files {
        char *character;
        int quantity;
        char *bit;
        char *value_bit;
        struct s_info_files *right;
        struct s_info_files *left;
        struct s_info_files *next;
    } t_info_files;

    typedef struct s_char_codes {
        char *character;
        char *code;
        struct s_char_codes *next;
    } t_char_codes;

#endif
