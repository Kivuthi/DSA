# include <stdio.h>
# define n 5

//int arr[n]
//for (i=0; i<5; i++)
//arr[i]

int stack [n];
int top = -1;

int push (int marks){
        if (top == n - 1){
                printf("Stack is full");

        } else {
            top ++;
            stack[top] = marks;
            printf("Marks added is %d", marks);
        }
}

void display () {
    int i;
    if (top == -1) {
        printf("Stack is empty");
    } else {
        for (i = top; i >= 0; i--) {
            printf("\n %d", stack[i]);
        }
    }
}

void pop () {
    int marks = stack[top];
    if (top == -1) {
        printf("Stack underflow");
    } else {

        top --;
        printf("Mark popped from top is %d", marks);
    }
}

int main () {
int i;

push (80); // 0
push (88); // 1
push (90); // 2

printf("First element in stack is: %d", stack[0]);

printf("Your marks are :");

display ();

//printf("Stack after pop");

pop ();

display ();
    return 0;
}

