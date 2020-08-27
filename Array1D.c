#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n, sum=0;
    int i=0;

    scanf("%d",&n);  

    int arr[n];

    while (i<n)
    {
        scanf("%d", &arr[i]);
        sum+= *(arr+i++);
    }


    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", *(n-1-i+arr));
    }
    

    return 0;
}