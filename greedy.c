#include <stdio.h>
#include <cs50.h>
#include <math.h>
int main(void)
{
    float dollars;
    int cents, leftover, quarter_count, dime_count, nickel_count, penny_count, coin_count;
    int quarter = 25, dime = 10, nickel = 5;
    do
    {
        printf("O hai! How much change is owed? \n");
        dollars = get_float();    
    }
    while (dollars < 0);
    cents = (int)round(dollars * 100);
    
    quarter_count = cents / quarter;
    leftover = cents % quarter;
    
    dime_count = leftover / dime;
    leftover = leftover % dime;
    
    nickel_count = leftover / nickel;
    leftover = leftover % nickel;
    
    penny_count = leftover;
    
    coin_count = quarter_count + dime_count + nickel_count + penny_count;
    printf("%i\n",coin_count);
     
      
    return 0;
}