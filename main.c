#include <stdio.h>
#include <string.h>
#include "dictionary.h"

#define GRID_SIZE 4

void travel(char grid[4][4],int x,int y, dic_node *head, char *str, bool flag[4][4])  
{  
    if ( x<0 ||x>= GRID_SIZE ||y<0||y>=GRID_SIZE||flag[x][y])  
        return; 
    bool find =false;
    strncat(str, &grid[x][y], 1);
    flag[x][y] = true;
    find = find_word(head, str);
    if(find)
        printf("%s\n", str);
  /*  printf("%s\n", str);
    {
        int i,j;
        for(i=0; i<4; i++)
        {
            for(j=0; j<4; j++)
            {
                printf("%d",flag[i][j]);

            }
            printf("\n");
        }
    }*/ 
    travel(grid,x+1,y,head,str,flag);
    travel(grid,x-1,y,head,str,flag);
    travel(grid,x,y+1,head,str,flag);
    travel(grid,x,y-1,head,str,flag);  
    travel(grid,x+1,y+1,head,str,flag);
    travel(grid,x-1,y+1,head,str,flag);
    travel(grid,x-1,y+1,head,str,flag);
    travel(grid,x+1,y-1,head,str,flag);  
} 

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("wrong arg number\n");
        return -1;
    }
    dic_node *head = create_node();
    char grid[4][4];
    int i, j;
    char *str = argv[2];
    char buf[16];
    bool flag[4][4];
    head->cur = '\0';
    get_words_from_file(argv[1], head);
    
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            grid[i][j] = *str;
            str ++;
            
        }
    }
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            memset(buf, 0, sizeof(buf));
            memset(flag,0,sizeof(flag));
            travel(grid, i,j,head,buf,flag );
        }
    }
    release_nodes(head);
    return 0;
}
