#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("error");
        return 1;
    }
    
    int key = atoi(argv[1]);
    printf("plaintext:");
    string k = get_string();
    printf("ciphertext:");
    for (int i = 0, n=strlen(k); i < n; i++)
    {
        if (isalpha(k[i]))
        {
            if (isupper(k[i]))
            {
                printf("%c", ((k[i] - 'A' + key) % 26) + 'A');    
            }
            else
            {
                printf("%c", ((k[i] - 'a' + key) % 26) + 'a');
            }
        }
        else
        {
            printf("%c", k[i]); 
        }
    }
    printf("\n");
    return 0;
}