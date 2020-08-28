#include <stdio.h>
#include <stdlib.h>

int main()
{
    int array[6][6]={0};
    int temp;

    for (int horz=0;horz<5;horz++)
        {
            for (int vert = 0; vert < 5; vert++)
            {
                scanf("%d",&temp);
                array[horz][vert]=temp;
            }        
        }

    for (int horz=0;horz<5;horz++)
        {
            for (int vert = 0; vert < 5; vert++)
                printf("%d ",array[horz][vert]);
                
            printf("\n");     
        }
    int p_b_hrz=0,p_b_vrt=0;
    int max_sum=0,temp_sum=0;

    for (p_b_hrz=0; p_b_hrz< 4; p_b_hrz++) //horz traversal
    {
        for (p_b_vrt=0; p_b_vrt<4; p_b_vrt++) // vert traversal
        {
            temp_sum=temp_sum+array[p_b_hrz][p_b_vrt]+array[p_b_hrz][p_b_vrt+1]+array[p_b_hrz][p_b_vrt+2];
            temp_sum=temp_sum+array[p_b_hrz+1][p_b_vrt+1];
            temp_sum=temp_sum+array[p_b_hrz+2][p_b_vrt]+array[p_b_hrz+2][p_b_vrt+1]+array[p_b_hrz+2][p_b_vrt+2];
            if(temp_sum>max_sum || p_b_hrz==0 && p_b_vrt==0)
                max_sum=temp_sum;
            temp_sum=0;
        }
    }
    printf("\n %d \n",max_sum);
    


    return 0;
}