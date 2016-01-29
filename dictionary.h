#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int bool;

#ifndef false
#define false 0
#endif

#ifndef true
#define true 1
#endif

#define LETTER_COUNT 26
typedef struct dic_node_t{
    char cur;
    bool complete;
    struct dic_node_t *childs[LETTER_COUNT];
}dic_node;

int char_to_int(char ch);
dic_node *create_node(void);
void insert_node(dic_node *head, char *str);
bool find_word(dic_node *head, const char *str);
bool find_word_and_mark_read(dic_node *head, const char *str);
bool get_words_from_file(const char *path, dic_node *head);
void release_nodes(dic_node *head);

#endif
