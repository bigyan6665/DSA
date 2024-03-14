#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
struct stack
{
    int size;
    char *ptr;
    int top;
};
void create_empty_stack(struct stack *s, int capacity)
{
    s->top = -1;
    s->size = capacity;
    s->ptr = (char *)malloc(s->size * sizeof(char)); // ptr points 1st memory block
    printf("\nStack created.\n");
}
void push(struct stack *s, char v)
{
    if (s->top == s->size - 1)
    {
        printf("\nThe stack is full!!!!!\n");
    }
    else
    {
        s->top = s->top + 1;
        s->ptr[s->top] = v;
    }
}
char pop(struct stack *s)
{
    char x;
    if (s->top == -1)
    {
        printf("\nThe stack is empty!!!!!\n");
    }
    else
    {
        x = s->ptr[s->top];
        s->top = s->top - 1;
    }
    return x;
}
void display(struct stack *s)
{
    if (s->top == -1)
    {
        printf("\nThe stack is empty!!!!!\n");
    }
    else
    {
        for (int i = s->top; i >= 0; i--)
        {
            printf("element%d = %c\n", i + 1, s->ptr[i]);
        }
    }
}
int evaluate_prefix(char a[])
{
    struct stack st;
    create_empty_stack(&st, strlen(a));
    for (int i = strlen(a) - 1; i >= 0; i--)
    {
        if (isdigit(a[i]))
        {
            push(&st, a[i] - '0');
        }
        else
        {
            int op2 = pop(&st);
            int op1 = pop(&st);
            switch (a[i])
            {
            case '+':
                push(&st, op2 + op1);
                break;
            case '-':
                push(&st, op2 - op1);
                break;
            case '*':
                push(&st, op2 * op1);
                break;
            case '/':
                push(&st, op2 / op1);
                break;
            case '^':
                push(&st, pow(op1, op2));
                break;
            }
        }
    }
    return pop(&st);
}
int main()
{
    int n = 100;
    char prefix[n];
    printf("Enter the prefix expression = ");
    scanf("%s", &prefix);
    int result = evaluate_prefix(prefix);
    printf("The result of the prefix expression is = %d", result);
    return 0;
}