/*
** EPITECH PROJECT, 2021
** victor header
** File description:
** lib my_hunterexercise
*/

#ifndef LIBRAY_H_
    #define LIBRAY_H_
    #include <string.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <stddef.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <sys/stat.h>
    #include <ctype.h>
    #include "./structs.h"
    #include <limits.h>

void my_itoa(long i, char *string);
void *my_memset(void *s, int c, int n);
void *my_calloc(int nmemb, int size);
void revstr(char *str1);
char *my_charcat(char *dest, char src);
int my_getnbr(char const *str);
int my_nbrlen(int nb);
char *ext_my_return_char(int nb, char *str, int neg);
char *my_return_char(int nb);
char *my_revstr(char *str);
char *my_strcat(char *dest, char *src);
int my_strcmp(const char *s1, const char *s2);
char *my_strdup(char *str);
char *my_strcpy(char *destination, char *source);
int my_strlen(char const *str);
void create_new(t_var *var, t_info_files *file);
void create_new_tree(t_var *var, t_info_files *file);
void create_tree(t_var *var, t_info_files *file);
void create_new_linkcode(t_var *var, t_info_files *file,
t_char_codes *temp_linked);
int fs_open_file(char const *filepath);
void errase_file(t_var *var);
void free_linked(t_info_files *file, t_char_codes *linked);
void free_words(t_var *var);
void free_struct(t_var *var);
char *get_code(t_var *var, t_char_codes *linked, char *word);
char *get_code_char(t_var *var, t_char_codes *linked, char word);
char get_byte(char *byte);
void get_bits(t_var *var, char *str_code);
void quantity_words(t_var *var);
int get_lenword(t_var *var, int i);
char *get_word(t_var *var, int i, int len_word);
void get_bit_value(t_var *var, t_info_files *file, t_char_codes *linked,
char *prev_value_bit);
void repeat_words(t_var *var);
t_info_files *ini_new_info_files(t_var *var);
t_char_codes *ini_new_char_files(t_var *var, t_info_files *file);
t_info_files *ini_new_info_files_tree(t_var *var, t_info_files *first,
t_info_files *second);
t_info_files *init_file(void);
t_char_codes *init_char(void);
t_var *init_var(void);
void sort_date_linked(t_info_files *linked);
void printlinked(t_info_files *file);
void printlinked_code(t_char_codes *tmp);
int find_index_array(t_var *var, char to_find);
int find_str_array(t_var *var, char *to_find);
void change_code(t_var *var, t_char_codes *linked);
void save_text(t_var *var, int fd);
void save_word(t_var *var);
void save_word2(t_var *var, int i, int len_word);
void save_charcters(t_var *var);
void save_nodes(t_var *var, t_info_files *file);
void func_save_temp(t_info_files *save_tmp, t_info_files *link);
void save_on_pointer(t_info_files *i, t_info_files *temp);
void write_compressed_file(t_var *var, t_char_codes *linked);
void bitwise_print(t_var *var, t_char_codes *linked);
void write_key(t_var *var, t_char_codes *linked);
char *char_to_code(char letter);
void un_char_str(t_var2 *var, char *str);
void get_dictionary2(t_var2 *var);
void get_dictionary(t_var2 *var);

#endif
