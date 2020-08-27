#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

typedef struct
{
    char name[100];
    unsigned int number;

}instance;

int my_compare (const void * a, const void * b)
{
    const instance* _a = (const instance*) a;
    const instance* _b = (const instance*) b;

    return(strcmp(_a->name,_b->name));
}


int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int array_length=0;
    char temp_str[100];

    scanf("%d",&array_length);

    instance* array = (instance*) malloc(sizeof(instance)*array_length);

    instance* found_pointer = (instance*) malloc(sizeof(instance));

    for (int i=0; i<array_length; i++) 
        scanf("%s %u",(array+i)->name , (array+i)->number);

    qsort(array,array_length,sizeof(instance),my_compare);
    
    int found=FALSE,found_id=0;

    while (scanf("%s",temp_str)>=0) 
    {
        found_pointer = (instance*)bsearch(temp_str,array->name,array_length,sizeof(instance),my_compare);

        if(found_pointer!=NULL)
        {
            printf("%s=%u \n", found_pointer->name , found_pointer->number);
        }else
        {
            printf("Not found \n");
        }
        
    }

    return 0;
}
