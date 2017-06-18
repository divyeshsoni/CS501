#include<cs50.h>
#include<stdio.h>
int main(void)
{
    int h; 
  do {
		printf("Height:");
		h = get_int();
        if (h == 0)
        {
            return 0;
        }
	} while (h < 1 || h > 23);
 for(int i=h;i>0;--i)
 {
     for(int j=i;j>1;--j)
     {printf(" ");
     }
     for(int k=i;k<=h+1;++k)
     {printf("#");
 }
 printf("\n");
}
}

