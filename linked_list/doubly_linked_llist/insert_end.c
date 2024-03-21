#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
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
void insert_end(struct linked_list *ll, int x)
{
    ll->newnode = (struct Node *)calloc(1, sizeof(struct Node));
    ll->newnode->data = x;
    if (ll->first == NULL && ll->last == NULL)
    {
        ll->newnode->next = NULL;
        ll->newnode->prev = NULL;
        ll->first = ll->newnode;
        ll->last = ll->newnode;
    }
    else
    {
        ll->newnode->prev = ll->last;
        ll->newnode->next = NULL;
        ll->last->next = ll->newnode;
        ll->last = ll->newnode;
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
    insert_end(ll, 5);
    insert_end(ll, 7);
    insert_end(ll, 9);
    display(ll);
    return 0;
}