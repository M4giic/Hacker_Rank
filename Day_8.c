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

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int array_length=0;
    int temp_str_index=0,name_finished_index=0;
    char* temp_str;

    int line_finished=FALSE;

    int name_finished=0;

    scanf("%d",&array_length);
    getchar();

    instance* array = (instance*) malloc(sizeof(instance)*array_length);

    for (int i=0; i<array_length; i++) 
    {
        scanf("%s %u",(array+i)->name , &((array+i)->number));
        /*

        fgets(temp_str,100,stdin);

        
        name_finished=FALSE;
        line_finished=FALSE;
        temp_str_index=0;
        name_finished_index=0;

        while (!line_finished)
        {
             if(*(temp_str+temp_str_index)==' ')
             {
                 name_finished=TRUE;
                 name_finished_index = temp_str_index;
             }

             if(!name_finished)
                 (array+i)->name[temp_str_index] = *(temp_str + temp_str_index);
             else
             {
                 (array+i)->number[temp_str_index-name_finished_index] = *(temp_str + temp_str_index+1);
             }
            
             temp_str_index++;

             if(*(temp_str+temp_str_index)==0x0A)
                line_finished=TRUE;
        }
        */

    }

    for (int i=0; i<array_length; i++) 
        printf("%s = %u \n", (array+i)->name , (array+i)->number);


    int found=FALSE,found_id=0;

    while (scanf("%s",temp_str)) 
    {
          found=FALSE;
        for (int i=0; i<array_length; i++) 
            {
                if (strcmp(temp_str,(array+i)->name)) 
                {
                  found=TRUE;  
                  found_id=i;
                  i=array_length;
                }
            }
                if(found)
                    printf("%s=%u \n", (array+found_id)->name , (array+found_id)->number);
                else
                    printf("nof found \n");
    }

    return 0;
}