#include "dictionary.h"

int char_to_int(char ch)
{
    if((ch >= 'a') && (ch <= 'z'))
        return ch-'a';
    else if((ch >= 'A') && (ch <= 'Z'))
        return ch-'A';
    else if(ch == '\'')
        return 26;
    return -1;
}

dic_node *create_node(void)
{
     dic_node *node = (dic_node *)malloc(sizeof(dic_node));
     int i;
     node->complete = false;
     for(i=0; i<LETTER_COUNT; i++)
         node->childs[i] = NULL;
     return node;
}
void insert_node(dic_node *head, char *str)
{
    if((head == NULL) || (str == NULL))
    {
        head = create_node();
    }
    dic_node *temp = head;
    int index = -1;
    while(*str != '\n')
    {
       index = char_to_int(*str);
       if(index != -1)
       {
            if (temp->childs[index] == NULL)
            {
                temp->childs[index] = create_node();
            }        
            temp = temp->childs[index];
            temp->cur = *str;
            str ++;
       }
       else
           break;
    }
    temp->complete = true;
}


bool find_word(dic_node *head, const char *str)
{
    if((head == NULL) || (str == NULL))
    {
        return false;
    }
    dic_node* temp = head;
    int index;
    do
    {
       index = char_to_int(*str);
       if( index != -1) 
       {
           temp = temp->childs[index];
           if (temp == NULL)
               return false;
           str++;
       }
    }while (*str != '\0');
    return temp->complete;
}

bool get_words_from_file(const char *path, dic_node *head)
{
    FILE *fp = fopen(path, "rb");
    char buf[128];
    if(fp != NULL)
    {
        while(!feof(fp))
        {
            if(fgets(buf, sizeof(buf), fp))
            {
                //printf("%d: %s", i++, buf);
                insert_node(head, buf);
            }
	    }
	    fclose(fp);
    }
    else
        return false;
    return true;
}


void release_nodes(dic_node *head)
{
   if (head == NULL)
       return;
   int i;
   for(i = 0; i < LETTER_COUNT; i++)
   {
       if(head->childs[i] != NULL)
       {
           release_nodes(head->childs[i]);
       }
      
   }
   free(head);
}
