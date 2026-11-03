
#include <string.h>

char stack[100];

bool isValid(char* s) 
{
    int top = -1;
    int i;

    for(i = 0; s[i] != '\0'; i++)
    {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            stack[++top] = s[i];
        }
        else
        {
            if(top == -1)
                return false;

            char ch = stack[top--];

            if((s[i] == ')' && ch != '(') ||
               (s[i] == '}' && ch != '{') ||
               (s[i] == ']' && ch != '['))
            {
                return false;
            }
        }
    }

    return top == -1;
}
