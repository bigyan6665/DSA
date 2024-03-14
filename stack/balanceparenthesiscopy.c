#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
struct Stack
{
    int top;
    int size;
    char *ptr; // pointer
};
void createStack(struct Stack *s, int cap)
{
    s->top = -1;
    s->size = cap;
    s->ptr = (char *)malloc(s->size * sizeof(char));
    printf("\nStack created\n");
}
int isempty(struct Stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    return 0;
}
int isfull(struct Stack *s)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    return 0;
}
void push(struct Stack *s, char v)
{
    if (s->top == s->size - 1)
    {
        printf("\nThe Stack is full!!!!!\n");
    }
    else
    {
        s->top = s->top + 1;
        s->ptr[s->top] = v;
    }
}
char pop(struct Stack *s)
{
    char x;
    if (s->top == -1)
    {
        printf("\nThe Stack is empty!!!!!\n");
    }
    else
    {
        x = s->ptr[s->top];
        s->top = s->top - 1;
    }
    return x;
}
bool areParenthesesBalanced(char *expression)
{
    struct Stack st;
    createStack(&st, strlen(expression));
    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
            push(&st, expression[i]);
        else if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']')
        {
            if (isempty(&st))
                return false;
            char popped = pop(&st);
            if ((expression[i] == ')' && popped == ')') ||
                (expression[i] == '}' && popped == '}') ||
                (expression[i] == ']' && popped == ']'))
                return false;
        }
    }
    return true;
}

int main()
{
    char expression[100];
    printf("Enter the infix expression: ");
    scanf("%s", expression);

    if (areParenthesesBalanced(expression))
        printf("Parentheses are balanced.\n");
    else
        printf("Parentheses are not balanced.\n");

    return 0;
}
