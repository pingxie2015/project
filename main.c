#include <stdio.h>
#include "functions.h"

int main(){
    FILE *fp = fopen("words", "rb");
    char buf[256];
    if(fp != NULL)
    {
        while(fgets(buf, sizeof(buf), fp))
	{
	    printf("%s\n", buf);
	}
	fclose(fp);
    }
    print_hello();
    printf( "The factorial of 5 is ");
    return 0;
}
