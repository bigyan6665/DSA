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
int node_count(struct linked_list *ll)
{
    int count = 1;
    if (ll->first == NULL && ll->last == NULL)
    {
        count = 0;
        return count;
    }
    else if (ll->first == ll->last)
    {
        count = 1;
        return count;
    }
    else
    {
        struct Node *temp;
        temp = ll->first;
        while (temp != ll->last)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
}
void insert_middle(struct linked_list *ll, int x, int pos)
{
    int node_no = node_count(ll);
    if (pos == 1)
    {
        printf("\ninsert_middle() donot insert element at first position\n");
        return;
    }
    else if (pos == node_no + 1)
    {
        printf("\ninsert_middle() donot insert element at last position\n");
        return;
    }
    else if (pos <= 0 || pos >= node_no + 2)
    {
        printf("\ninvalid insertion position\n");
        return;
    }
    else if (node_no == 0)
    {
        printf("\nInsertion at middle isnot possible because 0 nodes are present\n");
        return;
    }
    else if (node_no == 1)
    {
        printf("\nInsertion at middle isnot possible because only 1  node is present\n");
        return;
    }
    int curr = 1;
    ll->newnode = (struct Node *)calloc(1, sizeof(struct Node));
    ll->newnode->data = x;
    struct Node *temp1;
    struct Node *temp2;
    temp1 = ll->first;
    while (curr != pos - 1)
    {
        temp1 = temp1->next;
        curr++;
    }
    temp2 = temp1;
    ll->newnode->next = temp1->next;
    temp2 = temp2->next;
    temp2->prev = ll->newnode;
    temp1->next = ll->newnode;
    ll->newnode->prev = temp1;
    printf("\nElement added successfully\n");
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
    insert_middle(ll, 55, 3);
    display(ll);
    return 0;
}