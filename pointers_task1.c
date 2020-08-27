#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void update(int* a, int* b);

int main(int argc, char* argv[])
{
    int a,b;
    printf("Values to be added \r\n a:");
      scanf("%d",&a);
    printf("\r\n b: ");
      scanf("%d",&b);

    update(&a,&b);

    printf("After update \r\n a: %d \r\n b: %d \r\n",a,b);
    
    return 0;
}

void update(int* a, int* b)
{
    int temp_a=*a, temp_b=*b;
    *a=temp_a+temp_b;
    *b=abs(temp_a-temp_b);

}
