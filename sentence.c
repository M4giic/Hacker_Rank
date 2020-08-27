#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char s2[1000];
    int i=0;

    memset(s2,sizeof(s2),NULL);

    printf("please insert sentece: ");
    fgets(s2,sizeof(s2),stdin);

    while (s2[i]!=NULL)
    {
        if(s2[i]!=' ')
            printf("%c",s2[i]);
        else
            printf("\n");
        i++;
    }
    

    return 0;
}