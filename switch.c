#include <stdio.h>
#include <string.h>
#define n 5
#define MAX_LEN 50

char menu [n] [MAX_LEN];
int top =-1;

//push function
int push (char item[]) {
    if (top == n-1) {
        printf("menu is full/n");
        return -1;
    } else {
        top ++;
        strcpy(menu[top], item);
        return 0;
    }
}

//pop functio
void pop () {
    char item[50];
    if (top == -1) {
        printf("Stack is empty");
        // return -1;
    } else {
        strcpy(item, menu[top]);
        top--;
        // return 0;
    }
}

//display function
void display (){
    int i;
    if (top == -1) {
        printf("Stack is empty");
    } else {
        for (i=top; i>=0; i--) {
            printf("%s", menu[i]);
        }
    }
}

int main() {
char menu [50];
int choice;
 
do {
    printf("Choose!!");
    printf("Case1: push items");
    printf("Case2: Pop Items");
    printf("Case3: Display");
    printf("case4: Exit");
    printf("Enter your choice");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            push("Chapati");
            push("Mandazi");
            push("Kaimati");
            push("Samosa");
            push("Mahamri");
            break;

        
        case 2:
            pop();
            break;
        
        case 3:
            display();
            break;

        case 4:
            printf("Exited");

        default:
            printf("Invalid choice");
    }
} 
  while (choice !=4);

    return 0;
}

