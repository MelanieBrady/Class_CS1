/* Linked List Worksheet
Remove all the elements of a particular value from asingular linked, non-circular, unsorted,linked list. 
We could repeatedlycall contains and delete on the linked listto emulatesuch a function. 
This might not be the most efficient method.

1. What is the worst case Big-O runtime for the above described method in terms of the length of the linked list (n)?
If you are already working with a predefined and created linked list, all just for deleting the entire linked list? Well, the act of deleting itself should just be O(1)

2. Draw a linked list with 8 elements that has the worst number of comparisons for deleting all nodes with a value 4.
[] -> [] -> [] -> [] -> [] -> [] -> [] -> [] -> NULL
Well, the worst case for comparions? Would be searching the entire linked list so it would be O(n) then the O(1) per deletion. 
Either 4 is in the very last head or it's in all heads, but I'm not sure which one is practically worse.

3. Write an efficient removeAll(int value, struct Node * head)function that removes all elements with a given value from 
a linked with the given head.The function should return the new head of the Linked List.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next; //Node pointer
} Node;

Node *createNode(Node *head);
Node *removeAll(int value, Node *head);

int main ()
{
    int data, ripvalue, nodeTotal = 0;

    printf("How many nodes? ");
    scanf("%d", nodeTotal);

    for (int i = 0; i < nodeTotal; i++)
    {
        printf("What's the data at this node? ");
        scanf("%d", data); 
        if (i == 0) 
        {
        Node *head = create(value);
        }
        else {

        }

    }

    printf("What's the value to delete? ");
    scanf("%d", ripvalue); 

}

void *create (int data) 
{
    Node *temp = malloc(sizeof(Node *));
    temp->data = data;
    temp->next = NULL;

    
    return;
}



Node *removeAll(int value, Node *head);
{
    int value;
    Node *newHead = head; 

    //Go through every head, if it's null you're at the end of the list
    while (head != NULL)
    {
        //if the data at this node is equal to the value of the int
        if (Node->data == value)
        { //create a temp head and reconnect the nodes
            Node *temp = head->next;
            free(head);
            head = temp;
        }
        else //make the new head point to the next node. 
        {
            head = head->next;
        }
    }

    return Node *head;
}