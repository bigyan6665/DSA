#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int *arr;
    int top;
};
void create_empty_stack(struct stack *s, int capacity)
{
    s->top = -1;
    s->size = capacity;
    s->arr = (int *)malloc(s->size * sizeof(int)); // arr points 1st memory block
    printf("\nStack created.\n");
}
void push(struct stack *s)
{
    if (s->top == s->size - 1)
    {
        printf("\nThe stack is full!!!!!\n");
    }
    else if (s->top >= -1 && s->top < s->size - 1)
    {
        int new_item;
        printf("Enter item to add = ");
        scanf("%d", &new_item);
        s->top = s->top + 1;
        s->arr[s->top] = new_item;
        printf("\nItem pushed.\n");
    }
    else
    {
        printf("\nStack is not created!!!!!\n");
    }
}
int pop(struct stack *s)
{
    if (s->top == -1)
    {
        printf("\nThe stack is empty!!!!!\n");
    }
    else if (s->top >= 0 && s->top <= s->size - 1)
    {
        printf("Item popped = %d ", s->arr[s->top]);
        s->top = s->top - 1;
        printf("\nItem popped.\n");
    }
    else
    {
        printf("\nStack is not created!!!!!\n");
    }
}
void display(struct stack *s)
{
    if (s->top == -1)
    {
        printf("\nThe stack is empty!!!!!\n");
    }
    else if (s->top >= 0 && s->top <= s->size - 1)
    {
        for (int i = s->top; i >= 0; i--)
        {
            printf("element%d = %d\n", i + 1, s->arr[i]);
        }
    }
    else
    {
        printf("\nStack is not created!!!!!\n");
    }
}
int main()
{
    int cap = 0;
    struct stack obj;
    obj.top = -2;
    char choice;
    while (1)
    {
        system("cls");
        printf("\na.create empty stack.\n");
        printf("\nb.push.\n");
        printf("\nc.pop.\n");
        printf("\nd.display.\n");
        fflush(stdin);
        printf("\nEnter your choice = ");
        scanf("%c", &choice);
        fflush(stdin);
        switch (choice)
        {
        case 'a':
            printf("Enter the capacity of the stack =");
            scanf("%d", &cap);
            create_empty_stack(&obj, cap);
            break;
        case 'b':
            push(&obj);
            break;
        case 'c':
            pop(&obj);
            break;
        case 'd':
            display(&obj);
            break;
        default:
            printf("\nWrong character entered!!!!!\n program exited\n");
            exit(0);
        }
        printf("\nPress any key to continue.\n");
        getch();
    }
    return 0;
}