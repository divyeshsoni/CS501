#include <cs50.h>
#include <stdio.h>
int main(void)
{
   printf("Minutes: ");
   int minutes=get_int();
   int bottles=(minutes*128*(1.5))/16;
   printf("Bottles: %i",bottles);
}