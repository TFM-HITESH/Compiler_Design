#include <stdio.h>
#include <ctype.h>
#include <string.h>
void lexicalanalysis(const char *input)
{
    int i = 0;
    while (input[i] != '\0')
    {
        while (isspace(input[i]))
        {
            i++;
        }
        if (isalpha(input[i]) || input[i] == '_')
        {
            char buf[1000];
            int j = 0;
            while (isalnum(input[i]) || input[i] == '_')
            {
                buf[j++] = input[i++];
            }
            buf[j] = '\0';
            if (strcmp(buf, "for") == 0 || strcmp(buf, "int") == 0 || strcmp(buf, "char") == 0 || strcmp(buf, "double") == 0 ||
                strcmp(buf, "return") == 0 || strcmp(buf, "float") == 0 || strcmp(buf, "void") == 0 || strcmp(buf, "continue") == 0 ||
                strcmp(buf, "break") == 0 || strcmp(buf, "goto") == 0 || strcmp(buf, "if") == 0 || strcmp(buf, "register") == 0 ||
                strcmp(buf, "typedef") == 0 || strcmp(buf, "switch") == 0 || strcmp(buf, "do") == 0 || strcmp(buf, "long") == 0 ||
                strcmp(buf, "extern") == 0 || strcmp(buf, "while") == 0 || strcmp(buf, "unsigned") == 0 || strcmp(buf, "short") == 0)
            {
                printf("Token - Keyword: %s\n", buf);
            }
            else
            {
                printf("Token - Identifier: %s\n", buf);
            }
        }
        else if (isdigit(input[i]))
        {
            char buf[1000];
            int j = 0;
            while (isdigit(input[i]))
            {
                buf[j++] = input[i++];
            }
            buf[j] = '\0';
            printf("Token - Number: %s\n", buf);
        }
        else
        {
            switch (input[i])
            {
            case '+':
            case '-':
            case '=':
                if (input[i] == input[i + 1])
                {
                    printf("Token - Operator: %c%c\n", input[i], input[i + 1]);
                    i += 2;
                }
                else
                {
                    printf("Token - Operator: %c\n", input[i]);
                    i++;
                }
                break;
            case '<':
            case '>':
                if (input[i + 1] == '=')
                {
                    printf("Token - Operator: %c=\n", input[i]);
                    i += 2;
                }
                else
                {
                    printf("Token - Operator: %c\n", input[i]);
                    i++;
                }
                break;
            case '*':
            case '/':
                printf("Token - Operator: %c\n", input[i]);
                i++;
                break;
            case '(':
            case ')':
            case '{':
            case '}':
            case ';':
            case ',':
            case '&':
            case ']':
            case '[':
                printf("Token - Punctuator: %c\n", input[i]);
                i++;
                break;
            case '"':
                int q = i + 1;
                printf("Token - Literal: ");
                while (input[q] != '"')
                {
                    printf("%c", input[q]);
                    q++;
                }
                printf("\n");
                i = ++q;
                break;
            default:
            }
        }
    }
}
int main()
{
    char input[1000];
    printf("Enter the input string: ");
    fgets(input, sizeof(input), stdin);
    printf("\n========================================================== \n");
    lexicalanalysis(input);
    return 0;
}