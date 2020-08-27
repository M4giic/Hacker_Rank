#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int i = 4;
    double d = 4.0;
    char s[] = "HackerRank ";

    int i2;
    double d2;
    char s2[100];

    scanf("%d",&i2);
        scanf("%lf",&d2);
            getchar();
            fgets(s2,sizeof(s2),stdin);


    printf("%d \r\n",i2+i);
    printf("%.1f \r\n",d2+d);
    printf("HackerRank %s \r\n",s2);

    return 0;
}