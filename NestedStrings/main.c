#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//The user input can be just ''"(", "{", "[", "]", "}" and/or ")"
int main()
{

    char input[6];

    printf("Input the expression");
    gets(input);
    int maxAux;
    //Fixed numbers only to see with all is correct, we dont want to use this in production :)
    maxAux = 6;
    int found = 1;

    for (int i = 0; i < 6; i++)
    {
        if (input[i] == '{')
        {
            if (input[i + 1] == '}')
                found = 1;
            else if (input[maxAux] == '}')
                found = 1;
            else
            {
                found = 0;
            }
        }
        else if (input[i] == '[')
        {
            if (input[i + 1] == ']')
                found = 1;
            else if (input[maxAux] == ']')
                found = 1;
            else
            {
                found = 0;
            }
        }
        else if (input[i] == '(')
        {
            if (input[i + 1] == ')')
                found = 1;
            else if (input[maxAux] == ')')
                found = 1;
            else
            {
                found = 0;
            }
        }
        maxAux--;
    }
    if (found == 1)
        printf("Nested");
    else
        printf("Not Nested");
}