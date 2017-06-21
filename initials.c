#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main() {
    string s = get_string();
    printf("%c", toupper(s[0]));
    int i,len=strlen(s);
    for( i = 1; i < len; i++)
        if(s[i-1] == ' ')
            printf("%c", toupper(s[i]));
            printf("\n");
            return 0;
}