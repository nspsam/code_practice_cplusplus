#include <iostream>
#include <string>

using namespace std;

int get_closing_paren_position(char * string, int position)
{
    int open_nested_parens_count = 0;
    int nested_paren_check = 0;
    int close_nest_parens_pos = -1;

    if(NULL == string)
    {
        printf("Invalid string\n");
        return 0;
    }

    for(int i = 0; string[i] != '\0'; ++i)
    {
        if(string[i] == '(')
        {
            open_nested_parens_count++;
            if(i == position)
                nested_paren_check = open_nested_parens_count-1;
            printf("pos- (: %d\n", i);
        }
        else if(string[i] == ')')
        {
            open_nested_parens_count--;
            printf("pos- ): %d\n", i);
            if(open_nested_parens_count < 0)
            {
                close_nest_parens_pos = -1;
                break;            	
            }
            if(open_nested_parens_count == nested_paren_check)
            {
                close_nest_parens_pos = i;
                break;
            }
        }
    }

    return close_nest_parens_pos;
}

int main() 
{
    char string_input[] = "Sometimes (when I nest them (my parentheticals) too much (like this (and this))) they get confusing.";

    printf("Position: %d\n", get_closing_paren_position(string_input, 10));
    return 0;
}
