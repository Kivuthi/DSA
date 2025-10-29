// 13 16 18
//printf(stack[top])
//printf(top)
#define n 5
#include<stdio.h>
int queue[n];
int rear;
int front;

//enqueue function
int enqueue(int item)
{
    if (rear==n-1)
    {
        printf("Queue is full\n");

    } else if(front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear]=item;
        
    }
    else{
        rear++;
        queue[rear]=item;
    }
    // printf("enqueued!");
}

void display () 
{
    int i;
    int item;
    if(rear==0)
    {
        printf("Queue is empty\n");
    }
    else
    {

        for(i=front;i<=rear;i++)
        {
        printf("%d \n", queue[rear]);
        }
    }

}

void dequeue() {
    int item;
    if (((front == -1 ) && (rear == -1)) || (front>rear)){
        printf("Underflow");
    } else if (front == rear) {
        item=queue[front];
        front = rear = -1;

    } else {
        printf("The element dequeued is \n");
        front = front + 1;
        
    }
}

int main()
{

   printf("Queue operations\n");

     enqueue(32);
     enqueue(56);
     enqueue(45);
     display();

    dequeue();

    printf("\n item after dequeue is:");
    display();

    return 0;
}

