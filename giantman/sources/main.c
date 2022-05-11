/*
** EPITECH PROJECT, 2022
** Fundamentalfunctions
** File description:
** my_charcat
*/

#include "./../../includes/library.h"

void get_text(t_var2 *var)
{
    int size = 0;
    struct stat buf;

    stat(var->filepath, &buf);
    size = buf.st_size;
    var->arraytext = malloc(sizeof(char) * size + 1);
    memset(var->arraytext, '\0', size + 1);
    read(var->fd, var->arraytext, size);
}

t_var2 *init_var2(void)
{
    t_var2 *var = malloc(sizeof(t_var));
    var->fd = -1;
    var->filepath = NULL;
    var->arraytext = NULL;
    var->dic = NULL;
    var->word = NULL;
    var->code = NULL;
    var->compressed_binari = NULL;
    var->total_char = 0;
    return (var);
}

void free_main(t_var2 *var)
{
    free(var->arraytext);
    free(var->dic);
    for (int n = 0; var->word[n] != NULL; n++) {
        free(var->word[n]);
        free(var->code[n]);
    }
    free(var->compressed_binari);
    free(var->word);
    free(var->code);
    free(var);
}

void print_result(void)
{
    int fd = open("temp", O_RDONLY);
    int size = 0;
    struct stat buf;
    char *result = NULL;

    stat("temp", &buf);
    size = buf.st_size;
    result = malloc(sizeof(char) * size + 1);
    memset(result, '\0', size + 1);
    read(fd, result, size);
    write(1, result, size);
    write(fd, "", 0);
    close(fd);
}

int main(int argc, char **argv)
{
    t_var2 *var = init_var2();

    var->filepath = argv[1];
    fs_open_file(var->filepath);
    var->fd = open(var->filepath, O_RDONLY);
    get_text(var);
    get_dictionary(var);
    print_result();
    free_main(var);
    return (0);
}
