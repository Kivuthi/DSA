#include <stdio.h>
#define n 5

int stack[n];
int top = -1;


// Push function
int push(int item) {
    if (top == n - 1) {
        printf("Stack overflow\n");
        return -1;
    } else {
        top++;
        stack[top] = item;
        return 0;
    }
}

// Pop function
int pop() {
    if (top == -1) {
        printf("Stack is empty\n");
        return -1;
    } else {
        int poppedItem = stack[top];
        top--;
        return poppedItem;
    }
}

// Display function
void display() {
    int i;
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        for (i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    push(13);
    push(39);
    push(43);
    push(5);

    printf("Stack after pushes:\n");
    display();

    printf("\nPopped item: %d\n", pop());

    printf("\nStack after pop:\n");
    display();

    push('chapati');
    push('mandazi');
    push('kaimati');
    push('mahamri');
    push('samosa');

    display();

    return 0;
}
