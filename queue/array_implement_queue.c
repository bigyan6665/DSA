#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct queue
{
    int size;
    int *arr;
    int rear;
    int front;
};
void create_linear_queue(struct queue *s, int capacity)
{
    s->rear = -1;
    s->front = 0;
    s->size = capacity;
    s->arr = (int *)malloc(s->size * sizeof(int)); // arr points 1st memory block
    printf("\nlinear Queue created.\n");
}
void enqueue(struct queue *s)
{
    if (s->rear == s->size - 1)
    {
        printf("\nThe queue is full!!!!!\n");
    }
    else 
    {
        int new_item;
        printf("Enter item to add = ");
        scanf("%d", &new_item);
        s->rear = s->rear + 1;
        s->arr[s->rear] = new_item;
        printf("\nItem enqueued.\n");
    }
}
void dequeue(struct queue *s)
{
    if (s->front > s->rear)
    {
        printf("\nThe queue is empty!!!!!\n");
    }
    else 
    {
        int x = s->arr[s->front];
        printf("Item dequeued = %d ", x);
        s->front = s->front + 1;
    }
}
void display(struct queue *s)
{
    if (s->front > s->rear)
    {
        printf("\nThe queue is empty!!!!!\n");
    }
    else 
    {
        for (int i = s->front; i <= s->rear; i++)
        {
            printf("element%d = %d\n", i + 1, s->arr[i]);
        }
    }
}
int main()
{
    int cap = 0;
    struct queue obj;
    printf("Enter the capacity of the queue =");
    scanf("%d", &cap);
    create_linear_queue(&obj, cap);
    char choice;
    while (1)
    {
        system("cls");
        printf("\na.Enqueue.\n");
        printf("\nb.Dequeue.\n");
        printf("\nc.Display.\n");
        fflush(stdin);
        printf("\nEnter your choice = ");
        scanf("%c", &choice);
        fflush(stdin);
        switch (choice)
        {
        case 'a':
            enqueue(&obj);
            break;
        case 'b':
            dequeue(&obj);
            break;
        case 'c':
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