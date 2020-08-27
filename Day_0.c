#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char s2[100];

            fgets(s2,sizeof(s2),stdin);


    printf("Hello, World.\r\n");
    printf("%s \r\n",s2);

    return 0;
}