#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
    char s2[1000];
    int index=0;
    int digit_freq[10] = {0};

    memset(s2,sizeof(s2),NULL);

    printf("please insert sentece: ");
    fgets(s2,sizeof(s2),stdin);

    while (s2[index]!=NULL)
    {
        if(isdigit(s2[index])!=0)
        {
            (*(digit_freq+*(s2+index)-48))++;
            
        }
        index++;
    }

    for (size_t i = 0; i < 10; i++)
    {
        printf("%d ",*(digit_freq+i));
    }

    printf("\n");
    
    

    return 0;
}