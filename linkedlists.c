#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next; //Node pointer
} Node;

void print(Node *head);
void append(Node *head, int data);
Node *create(int data);
Node *push(Node *head, int data);
void letitgo(Node *head);
// int indexcounter(Node *head, int index);

int main()
{
    Node *head = create(1);

    append(head, 2);
    append(head, 3);
    head = push(head, 0);
    
    print(head);
    return 0;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

Node *create(int data)
{
    Node *temp = malloc(sizeof(Node *));
    temp->data = data;
    temp->next = NULL;

    return temp;
}

void append(Node *head, int data)
{
    Node *temp = create(data); 
    Node *fakehead = head;
    while(fakehead->next != NULL)
    {
        fakehead = fakehead->next;
    }

    fakehead->next = temp; 
}

Node* push(Node *head, int data)
{
    Node*temp = create(data);
    temp->next = head;

    return temp;
}

void letitgo(Node *head)
{
    while (head != NULL)
    {
    Node *temp = head->next;
    free(head);
    head = temp; 
    }
}

//first node is called head, last is called tail
// like an array but you can dynamically resize
// always ends with null


/*  Hardcoding
    Node *second = malloc(sizeof(Node *));
    second->data = 2;
    second->next = NULL;

    Node *third = malloc(sizeof(Node*));
    third->data = 3;
    third->next = NULL; 

    head->next = second; //linking them together
    second->next = third; */