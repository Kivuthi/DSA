#include <stdio.h>
#include <stdlib.h>

//To insert at a specified location

//create the node structure
struct Node {
    int data;
    struct Node *next;
};

// Insert some data in the first
void insertAtBegin(struct Node **head, int value) {
    //allocate mem
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    //pass data
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}


//function to insert nextTo
void insertNextTo(struct Node *prevNode, int value) {
    //check if previous Node == NULL

    if (prevNode == NULL) {
        printf("Previous node cannot be null");
        return;
    }

    //Allocate mem location]
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    //pass data
    newNode->data = value;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

void display (struct Node *head) {
    while (head != NULL){
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL");
}

int main() {
    struct Node *head = NULL;

    insertAtBegin(&head, 45);
    insertAtBegin(&head, 55);
    insertAtBegin(&head, 65);

    printf("values after inserting at beginning \n");
    display(head);

    //traverse to the node you want to insert
    struct Node *prevNode = head;

    while (prevNode != NULL && prevNode->data != 55) {
        prevNode = prevNode->next;
    }

    insertNextTo(prevNode, 60);

    printf("\n data after inserting after 55 \n");
    display(head);

    return 0;
}
