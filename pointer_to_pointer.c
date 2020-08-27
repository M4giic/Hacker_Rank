#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* pointer;
    int** pointer_to_pointer;

    int x_corr, y_corr, val;

    printf("insert corrds \nx: ");
    scanf("%d",&x_corr);
    printf("y: ");
    scanf("%d",&y_corr);

    printf("\nvalue to be added: ");
    scanf("%d",&val);

    *(*(pointer_to_pointer+x_corr)+y_corr)=val;

    printf("\nvalue added: ");
    printf("%d",(*(*(pointer_to_pointer+x_corr)+y_corr)));


    return 0;
}