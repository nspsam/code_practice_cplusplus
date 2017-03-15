#include <iostream>

/*
  Write an efficient function that checks whether any permutation ↴ of an input string is a palindrome 
 */
void has_palindrome_permutation(char * string)
{
    int charset[256] = {0};
    int count_chars_odd_rep = 0;
    
    for(int i=0; string[i] ; ++i)
    {
        if(charset[string[i]] == 0)
            charset[string[i]]++;
        else
            charset[string[i]]--;
    }
    
    for(int i=0; i<256; i++)
    {
        if(charset[i] % 2)
            count_chars_odd_rep++;
    }
    
    if(count_chars_odd_rep <= 1)
        printf("String has palindrom permutation\n");
    else
        printf("String has no palindrom permutation\n");
}

int main() {

    char string[] = "rammarppsaddas222234";
    
    has_palindrome_permutation(string);
    
    return 0;
}
