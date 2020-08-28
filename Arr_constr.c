#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

char* readline();
char** split_string(char*);

/*
 * Complete the arrayConstruction function below.
 */

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
        sum+=*(arr+i)
    return sum;
}

int check_diff (int* arr, int n)
{
    int abs_diff=0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
                abs_diff+=abs(*(arr+i)-*(abs+j));
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

    //this is not as simple. Time to modify 

    //First fill all members of array so that sum is ok

    //try to fill with 1, 2, 3 etc. rest should be is filled with values -1

    int mult=0,rest=0;
    int no_mult = TRUE;
    int i=1;

    while (no_mult)
    {
        if(n/i=0)
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
            *(arr+i)=mult
        else
            *(arr+i)=mult-1
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

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* q_endptr;
    char* q_str = readline();
    int q = strtol(q_str, &q_endptr, 10);

    if (q_endptr == q_str || *q_endptr != '\0') { exit(EXIT_FAILURE); }

    for (int q_itr = 0; q_itr < q; q_itr++) {
        char** nsk = split_string(readline());

        char* n_endptr;
        char* n_str = nsk[0];
        int n = strtol(n_str, &n_endptr, 10);

        if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

        char* s_endptr;
        char* s_str = nsk[1];
        int s = strtol(s_str, &s_endptr, 10);

        if (s_endptr == s_str || *s_endptr != '\0') { exit(EXIT_FAILURE); }

        char* k_endptr;
        char* k_str = nsk[2];
        int k = strtol(k_str, &k_endptr, 10);

        if (k_endptr == k_str || *k_endptr != '\0') { exit(EXIT_FAILURE); }

        int result_count;
        int* result = arrayConstruction(n, s, k, &result_count);

        for (int result_itr = 0; result_itr < result_count; result_itr++) {
            fprintf(fptr, "%d", *(result + result_itr));

            if (result_itr != result_count - 1) {
                fprintf(fptr, " ");
            }
        }

        fprintf(fptr, "\n");
    }

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}
