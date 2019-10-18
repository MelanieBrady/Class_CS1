/* Linked Lists First Attempt: 
-First node is called head, last is called tail
-Like an array but you can dynamically resize
-The last node always ends with null
-O(1) insert and remove in a LinkedList, while an ArrayList is O(n).
-Searching in ArrayList is O(1), while LinkedList is O(n)
http://cslibrary.stanford.edu/103/LinkedListBasics.pdf
*/

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
void deletelist(Node *head);
void deleteNode(Node *head); 

int main()
{
    Node *head = create(1);

    append(head, 2);
    append(head, 3);
    head = push(head, 0);
    
    print(head);
    return 0;
}

// Prints the entire list 
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

// Creates each node passed into it
Node *create(int data)
{
    Node *temp = malloc(sizeof(Node *));
    temp->data = data;
    temp->next = NULL;

    return temp;
}

// Append adds it to the end 
void append(Node *head, int data)
{
    Node *temp = create(data); 
    Node *current = head;
    while(current->next != NULL)
    {
        current = current->next;
    }

    current->next = temp; 
}

// Push is add to front 
Node* push(Node *head, int data)
{
    Node*temp = create(data);
    temp->next = head;

    return temp;
}

// Delete a single Node
void deleteNode(Node *head) 
{
// Copy value into node
//create temporary pointer, move the pointer to 
// free the one you want to delete 
}


// Deletes the entire list
void deletelist(Node *head)
{
    while (head != NULL)
    {
    Node *temp = head->next;
    free(head);
    head = temp; 
    }
}

// how to print backwards
// how to delete one node
// how to rearrange the list? 


/*  Hardcoding
    Node *second = malloc(sizeof(Node *));
    second->data = 2;
    second->next = NULL;

    Node *third = malloc(sizeof(Node*));
    third->data = 3;
    third->next = NULL; 

    head->next = second; //linking them together
    second->next = third; */