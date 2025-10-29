#include <stdio.h>
#include <stdlib.h>

//insert at the end

struct Node{
int data;
struct Node *next;

};

void insertAtEnd (struct Node **head, int item) {
    //allocate memory location
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    //pass data
    newNode->data = item;

    //point the next node to Null
    newNode->next = NULL;

    //check if the list is NULL
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    //traverse to the end
    struct Node *temp = *head;

    while (temp->next != NULL){
        temp = temp->next;

    }
        temp->next = newNode;

}

void display (struct Node *head){
    while(head != NULL){
        printf("%d -> ", head->data);

        head = head->next;
    }

    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;

     insertAtEnd(&head, 50);
     insertAtEnd(&head, 60);
     insertAtEnd(&head, 70);
     insertAtEnd(&head, 80);

     display(head);

     return 0;

}
