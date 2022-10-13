#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
} *first = NULL, *last = NULL;

void create(int A[], int n)                                     // function to create linked list by array
{
    first = (struct node *)malloc(sizeof(struct node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        node *p = (struct node *)malloc(sizeof(struct node));
        p->data = A[i];
        p->next = NULL;
        last->next = p;
        last = p;
    }
}

void Display(node *p)            // function to display the linked list
{
    p = first;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void Reverse(node *p)
{
    node *q, *r; // Sliding Poniter concept
    p = first;
    q = NULL;
    r = NULL;
    while (p)
    {
        r = q;       // r=>q & q=>p & p=>next
        q = p;       // after one loop, r == NULL, q = first and p = p->next so by 'q->next = r' will get address of prev node
        p = p->next; // we'll keep on doing this untill p!=NULL. when P == NULL, q would point to last node
        q->next = r; // So we'll have to make it as first node
    }
    first = q; // we made the last node as first node here.
}

int main()
{

    int A[] = {10, 20, 30, 40, 50, 60, 70, 80};

    create(A, 8);

    cout<<"Initial list : ";

    Display(first);

    Reverse(first);

    cout<<"List after reversing : ";

    Display(first);
}
