#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[]) 
{
    if(argc != 2) {
        printf("error");
        return 1;
    }
    
    for(int i = 0, l = strlen(argv[1]); i < l; i++)
    {
        argv[1][i] = tolower(argv[1][i]);
        
        if(!isalpha(argv[1][i])) {
            printf("error");
            return 1;
        }
    }
    printf("plaintext:");
    string s = get_string(), k = argv[1];
    printf("ciphertext:");
    int s_len = strlen(s), k_len = strlen(argv[1]);
    
    for(int i = 0, j = 0; i < s_len; i++)
        if(isalpha(s[i])) {
            if(j == k_len)
                j = 0;
            
            int tmp = (int) s[i] + ((int) k[j] % 97);
            
            if(isupper(s[i])) {
                if(tmp > 65 + 25)
                    tmp -= 26;
            } else {
                if(tmp > 97 + 25)
                    tmp -= 26;
            }
            
            printf("%c", (char) tmp);
            j++;
        } else
            printf("%c", s[i]);
        
    printf("\n");
    return 0;
}