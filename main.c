#include <stdio.h>
#include <string.h>
#include "dictionary.h"

#define GRID_SIZE 4

void travel(char grid[4][4],int x,int y, dic_node *head, char *str, bool flag[4][4])  
{  
    if ( x<0 ||x>= GRID_SIZE ||y<0||y>=GRID_SIZE)  
    {
        return; 
    }
    bool find =false;
    int i,j;
    char buf[16];
    memcpy(buf, str, sizeof(buf));
    strncat(str, &grid[x][y], 1);
    flag[x][y] = true;
    find = find_word_and_mark_read(head, str);
    if(find)
        printf("find %s\n", str);
//    printf("x=%d, y=%d, str=%s\n", x,y,str);
//    search the neighbors for possible output
    for(i=1; i>-2; i--)
    {
        for(j=1; j>-2; j--)
        {
            if(!(i==0 && j==0))
            {
                if(!flag[x-i][y-j])
                {
                    travel(grid, x-i,y-j,head,str,flag);        
                }
            }
        }
    }
    memcpy(str,buf,sizeof(buf));
    flag[x][y] = false;
/*
    travel(grid,x,y+1,head,str,flag);
    travel(grid,x+1,y,head,str,flag);
    travel(grid,x,y-1,head,str,flag);
    travel(grid,x-1,y,head,str,flag);  
    travel(grid,x+1,y+1,head,str,flag);
    travel(grid,x+1,y-1,head,str,flag);  
    travel(grid,x-1,y+1,head,str,flag);
    travel(grid,x-1,y-1,head,str,flag);  
*/
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
