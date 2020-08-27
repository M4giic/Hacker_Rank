#include <stdlib.h>
#include <stdio.h>

int main()
{   
    int n;

    printf("Give n: ");
    scanf("%d", &n);
    printf("\r\n");
    if(n%2==1)
        printf("Weird \n");
    else
    {
        if(n<=5)
            printf("Not Weird \n");
            else if(n<=20)
                printf("Weird \n");
                    else
                        printf("Not Weird \n");     
    }
    

    return 0;
}