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
void insert_start(struct linked_list *ll, int x)
{
    ll->newnode = (struct Node *)calloc(1, sizeof(struct Node));
    ll->newnode->data = x;
    if (ll->first == NULL && ll->last == NULL)
    {
        ll->newnode->next = ll->newnode;
        ll->newnode->prev = ll->newnode;
        ll->first = ll->newnode;
        ll->last = ll->newnode;
    }
    else
    {
        ll->first->prev = ll->newnode;
        ll->newnode->next = ll->first;
        ll->newnode->prev = ll->last;
        ll->last->next = ll->newnode;
        ll->first = ll->newnode;
    }
}
void delete_last(struct linked_list *ll)
{
    if (ll->first == NULL && ll->last == NULL)
    {
        printf("\nThere is no node in the linked list!!!\n");
        return;
    }
    else if (ll->first == ll->last)
    {
        free(ll->first);
        ll->first = NULL;
        ll->last = NULL;
        printf("\nlast node deleted successfully.\n");
    }
    else
    {
        struct Node *temp;
        temp = ll->first;
        while (temp->next != ll->last)
        {
            temp = temp->next;
        }
        free(ll->last);
        ll->last = temp;
        ll->last->next = ll->first;
        ll->first->prev = ll->last;
        printf("\nlast node deleted successfully.\n");
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
    do
    {
        printf("%d\t", i->data);
        i = i->next;
    } while (i != ll->first);
}
int main()
{
    struct linked_list *ll = create_ll();
    insert_start(ll, 5);
    insert_start(ll, 7);
    insert_start(ll, 9);
    display(ll);
    delete_last(ll);
    display(ll);
    return 0;
}