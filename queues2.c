# include <stdio.h>
# define MAX 5

int rear = -1, front = -1;
int queue[MAX];

void enqueue (int item) {
    if (rear == MAX - 1) {
        printf("Overflow");

    }
     else if (rear == -1 && front == -1) {
        rear = front = 0;
        queue[rear] = item;
    }
    else {
        rear = rear + 1 % MAX;

        queue[rear] = item;
    }
}

void dequeue() {
    if ((front == -1) && (rear == -1) || front > rear) {
        printf("Underflow");
    }
    else if (front == rear) {
        front = rear = 0;
    }
    else {
        front = front +1 %  MAX;
    }

}

int main () {
    int item;
    int i;

    enqueue(20);
    enqueue(30);
    enqueue(40);

    printf("Items enqueued are :\n");

    for (i = front; i <= MAX - 1; i++) {
        printf("%d \n", queue[i]);
    }

    dequeue ();

    for (i = front; i <= MAX - 1; i++) {
        printf("%d \n", queue[i]);
    }

}
