#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

/*
 * Please store the size of the integer array to be returned in result_count pointer. For example,
 * int a[3] = {1, 2, 3};
 *
 * *result_count = 3;
 *
 * return a;
 *
 */
int check_sum (int* arr, int n)
{
    int sum=0;
    for (int i = 0; i < n; i++)
        sum+=*(arr+i);
    return sum;
}

int check_diff (int* arr, int n)
{
    int abs_diff=0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
                abs_diff+=abs(*(arr+i)-*(arr+j));
    }
       
    return abs_diff;
}

int* arrayConstruction(int n, int s, int k, int* result_count) {
    
    int* arr = (int*) malloc (sizeof(int)*n );
    *result_count = n;

    int arr_found = FALSE;
    int s_okay = FALSE;
    int k_okay = FALSE;

    /* How to efficiently process this lexicographical smallest array?

        1) Create first element - prefereably 0 to be certain that
        array has smallest begning 
        2) Create n lon arr of 0
            a) check s - seperate funciton
            b) check k - seperate function
        3) if s is not okay

        4) if k is not okay

        5)control if all posibilites have been used
        ...
            a) check sum
            b) check abs diff.

    */

   //create array of 0
    for (int i = 0; i < n; i++)
        *(arr + i) = 0;
     
     if(check_diff(arr,n)==k && check_sum(arr,n)==s )
        return arr;

    //First fill all members of array so that sum is ok

    //try to fill with 1, 2, 3 etc. rest should be filled with values max-1

    int mult=0,rest=0;
    int no_mult = TRUE;
    int i=1;

    while (no_mult)
    {
        if(n/i==0)
            {
                mult=i;
                rest=n%i;
                no_mult = FALSE;
            }
        i++;
    }

    for (int i = 0; i < n; i++)
    {
        if(i<rest)
            *(arr+i)=mult;
        else
            *(arr+i)=mult-1;
    }

    if(check_diff(arr,n)<k)
        return -1;
    
    if(check_sum(arr,n)==s)
        s_okay = TRUE;

    if(check_diff(arr,n)==k && s_okay)
        return arr;

    /*
        Now that sum is ok and diff is not ok all operation should 
        be performed so that sum is never modified. 

        First try solution should be change value of 2 adjusted elements by 1

    */

    if(arr_found)
        return arr;
    else
        return -1;
}

int main ()
{
    int quer;
    int n,s,k;

    printf("give qurry number:");
    scanf("%d",&quer);

    int* result;
    int result_count;

    
for (int i = 0; i < quer; i++)
{
    printf("\n");
    printf("give params n: ");
    scanf("%d ",&n);
    scanf("s: %d ",&s);
    scanf("k: %d ",&k);

    printf("\n");

    result=arrayConstruction(n,s,k,&result_count);

    for (int result_itr = 0; result_itr < result_count; result_itr++) 
    {
            printf("%d", *(result + result_itr));

            if (result_itr != result_count - 1) 
                printf(" ");
            
    }

}

    




    return 0;
}