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
void create_circular_queue(struct queue *s, int capacity)
{
    s->rear = -1;
    s->front = -1;
    s->size = capacity;
    s->arr = (int *)malloc(s->size * sizeof(int)); // arr points 1st memory block
    printf("\ncircular Queue created.\n");
}
void enqueue(struct queue *s)
{
    int new_item;
    if (s->front == s->rear + 1 || (s->front == 0 && s->rear == s->size - 1))
    {
        printf("\nThe queue is full!!!!!\n");
    }

    printf("Enter item to add = ");
    scanf("%d", &new_item);
    if (s->front == -1)
    {
        s->front = 0;
    }
    s->rear = (s->rear + 1) % s->size;
    s->arr[s->rear] = new_item;
    printf("\nItem enqueued.\n");
}
void dequeue(struct queue *s)
{
    if (s->front == -1)
    {
        printf("\nThe queue is empty!!!!!\n");
    }

    int x = s->arr[s->front];
    if (s->front == s->rear)
    {
        s->front = -1;
        s->rear = -1;
    }
    else
    {
        s->front = (s->front + 1) % s->size;
    }
    printf("Item dequeued = %d ", x);
}
void display(struct queue *s)
{
    if (s->front == -1)
    {
        printf("\nThe queue is empty!!!!!\n");
    }
    else
    {
        int i = s->front;
        do
        {
            printf("%d ", s->arr[i]);
            i = (i + 1) % s->size;
        } while (i != (s->rear + 1) % s->size);
    }
}
int main()
{
    int cap = 0;
    struct queue obj;
    printf("Enter the capacity of the circular queue =");
    scanf("%d", &cap);
    create_circular_queue(&obj, cap);
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