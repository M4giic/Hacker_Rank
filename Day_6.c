#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define STR_LENGTH 10001


int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  

    char str[STR_LENGTH],even[STR_LENGTH/2],odd[STR_LENGTH/2];
    int N,index=0;

    scanf("%d", &N);
    //getchar();
    for(int i=0; i<N;i++)
    {
        scanf("%s",str);
        while (index<strlen(str)) 
        {
            if((index%2)==0)
                even[index/2]=str[index];
            else 
                odd[((index+1)/2)-1]=str[index];
            index++;
        }
        for (int j=0; j<index/2; j++) 
        {
            printf("%c",even[j]);
        }
        printf(" ");
        for (int j=0; j<((index+1)/2); j++) 
        {
            printf("%c",odd[j]);
        }
        printf("\n");
        index=0;
        
        //if (arr_item_endptr == arr_item_str || *arr_item_endptr != '\0') { exit(EXIT_FAILURE); }

    }

    return 0;
}
