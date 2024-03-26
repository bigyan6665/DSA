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
void delete_middle(struct linked_list *ll, int pos)
{
    int node_no = node_count(ll);
    if (pos == 1)
    {
        printf("\ndelete_middle() donot delete element of first position\n");
        return;
    }
    else if (pos == node_no)
    {
        printf("\ndelete_middle() donot delete element of last position\n");
        return;
    }
    else if (pos <= 0 || pos >= node_no + 1)
    {
        printf("\ninvalid deletion position\n");
        return;
    }
    else if (node_no == 0)
    {
        printf("\ndeleteion at middle isnot possible because 0 nodes are present\n");
        return;
    }
    else if (node_no == 1)
    {
        printf("\ndeletion at middle isnot possible because only 1  node is present\n");
        return;
    }
    int curr = 1;
    struct Node *temp1;
    temp1 = ll->first;
    while (curr != pos - 1)
    {
        temp1 = temp1->next;
        curr++;
    }
    struct Node *temp2= temp1->next;
    temp1->next = temp2->next;
    free(temp2);
    printf("\nElement deleted successfully\n");
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
    delete_middle(ll, 2);
    display(ll);
    return 0;
}