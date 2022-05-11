/*
** EPITECH PROJECT, 2022
** Fundamentalfunctions
** File description:
** my_charcat
*/

#include "./../../includes/library.h"

int find_index_array(t_var *var, char to_find)
{
    int i = 0;

    while (var->array_characters[i] != NULL) {
        if (var->array_characters[i][0] == to_find)
            return (i);
        i++;
    }
    return (-1);
}

int find_str_array(t_var *var, char *to_find)
{
    int i = 0;
    int instr = 0;
    while (var->array_characters[i] != NULL) {
        if (my_strcmp(var->array_characters[i], to_find) == 0)
            return (1);
        i++;
    }
    i = 0;
    while (var->array_words[i] != NULL) {
        if (my_strcmp(var->array_words[i], to_find) == 0)
            instr++;
        i++;
    }
    return (instr);
}

void write_text(t_var *var)
{
    int fd = open("./../giantman/temp",  O_WRONLY | O_APPEND | S_IRWXU
    | O_CREAT, 0777);
    write(fd, var->arraytext, my_strlen(var->arraytext));
    close(fd);
}

void main2(t_var *var, t_info_files *file, t_info_files *tmp,
t_char_codes *linked)
{
    save_charcters(var);
    if (var->sizetext >= 20000) {
        quantity_words(var);
        save_word(var);
        repeat_words(var);
        free_words(var);
    }
    save_nodes(var, file);
    create_tree(var, file);
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->bit = 0;
    get_bit_value(var, tmp, linked, var->prev_value_bit);
    close(var->fd2);
    var->fd = open(var->filepath, O_WRONLY | O_APPEND);
    write_key(var, linked);
    bitwise_print(var, linked);
    free_struct(var);
    free_linked(file, linked);
}

int main(int argc, char **argv)
{
    t_var *var = init_var();
    var->fd2 = -1;
    t_info_files *file = init_file();
    t_info_files *tmp = file;
    t_char_codes *linked = init_char();

    var->filepath = my_strdup(argv[1]);
    var->nbr_char_dic = 0;
    var->first = 0;
    fs_open_file(var->filepath);
    var->fd2 = open(var->filepath, O_RDONLY);
    file->value_bit = malloc(sizeof(char) * 100);
    var->bit_concate = malloc(sizeof(char) * 100);
    var->prev_value_bit = malloc(sizeof(char) * 5);
    var->prev_value_bit = my_strdup("1");
    var->num_words = 0;
    save_text(var, var->fd2);
    write_text(var);
    main2(var, file, tmp, linked);
    return (0);
}
