#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void solve(double meal_cost, int tip_percent, int tax_percent) 
{
    double total_cost;

    total_cost= meal_cost + (meal_cost*tip_percent)/100 + (meal_cost*tax_percent)/100 ;

    printf("Final cost: %.0lf \r\n",total_cost);


}

int main()
{
    double init_cost;
    int init_tip, init_tax;

     printf("Values to be added \r\n init_cost:");
      scanf("%lf",&init_cost);
    printf("\r\n init_tip: ");
      scanf("%d",&init_tip);
    printf("\r\n init_tax: ");
      scanf("%d",&init_tax);

    solve(init_cost,init_tax,init_tip);

    return 0;
}