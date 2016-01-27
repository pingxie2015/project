#include <stdio.h>
#include <string.h>
#include "dictionary.h"

#define GRID_SIZE 4

void travel(char *grid,int x,int y, dic_node *head)  
{  
    if ( x<0 ||x>= GRID_SIZE ||y<0||y>GRID_SIZE)  
        return false;  
    bool find =false;
    char buf[16];
    strcat(buf, &grid[x][y]);
    find = find_word(head, buf);
    if(find)
        printf("%s\n", buf);
    travel(grid,x+1,y);
    travel(grid,x-1,y);
    travel(grid,x,y+1);
    travel(grid,x,y-1);  
} 

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("wrong arg number\n");
        return -1;
    }
    dic_node *head = create_node();
    bool find = false;
    char grid[4][4];
    int i, j;
    char *str = argv[2];
    char buf[16];
    head->cur = '\0';
    get_words_from_file(argv[1], head);
    
    i=0;
    for(j=0; j<4; j++)
    {
        grid[i][j] = *str;
        str ++;
        i++;
        if(i%4 == 0)
            i=0;
    }
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            travel(grid, i,j );
        }
    }
    release_nodes(head);
    return 0;
}
