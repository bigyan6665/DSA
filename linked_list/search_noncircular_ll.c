#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct linked_list
{
    struct Node *first;
    struct Node *last;
    struct Node *newnode;
};
struct linked_list *create_ll()
{
    struct linked_list *ll;
    ll = (struct linked_list *)calloc(1, sizeof(struct linked_list));
    ll->first = NULL;
    ll->last = NULL;
    return ll;
}
void insert_start(struct linked_list *ll, int x)
{
    ll->newnode = (struct Node *)calloc(1, sizeof(struct Node));
    ll->newnode->data = x;
    if (ll->first == NULL && ll->last == NULL)
    {
        ll->newnode->next = NULL;
        ll->first = ll->newnode;
        ll->last = ll->newnode;
    }
    else
    {
        ll->newnode->next = ll->first;
        ll->first = ll->newnode;
    }
}
void linear_search(struct linked_list *ll, int x)
{
    int curr = 0, flag = 0;
    struct Node *temp = ll->first;
    if (ll->first == NULL && ll->last == NULL)
    {
        printf("\nNO nodes are present\n");
        return;
    }
    else
    {
        while ( temp != NULL)//for linear linked list
        {
            curr++;
            if (temp->data == x)
            {
                flag = 1;
                break;
            }
            temp = temp->next;
        }
    }
    if (flag == 1)
    {
        printf("\nItem found at %d position \n", curr);
    }
    else
    {
        printf("\nItem not found\n");
    }
}
void display(struct linked_list *ll)
{
    if (ll->first == NULL && ll->last == NULL)
    {
        printf("\nThere is no node in the linked list!!!\n");
        return;
    }
    struct Node *i;
    i = ll->first;
    while (i != NULL)
    {
        printf("%d\t", i->data);
        i = i->next;
    }
}
int main()
{
    struct linked_list *ll = create_ll();
    insert_start(ll, 5);
    insert_start(ll, 7);
    insert_start(ll, 9);
    display(ll);
    linear_search(ll, 7);
    return 0;
}