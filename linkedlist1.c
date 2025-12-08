#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtBegin (struct Node **head, int item){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = item;
    newNode->next = *head;
    *head = newNode;
};

void display(struct Node *head){
    while(head != NULL){
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("Null");
}

int main() {
    struct Node *head = NULL;

    insertAtBegin(&head, 10);
    insertAtBegin(&head, 20);
    insertAtBegin(&head, 30);
    insertAtBegin(&head, 40);

    display(head);

    return 0;
}
