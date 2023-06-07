#include <stdio.h>
#define size 5          // size of the queue
int arr[size];
int front = 0;
int rear = 0;
int isQueueEmpty() {
   if (front == rear)
       return 1;
    else
   return -1;
}
void dequeue() {
   if (isQueueEmpty() == 1)
       printf("Queue is Empty.\n");
   else {
       printf("Dequeued element = %d\n", arr[front]);
       front++;
   }
}
int isQueueFull() {
   if (rear == size)
       return 1;
       else
   return -1;
}
void enqueue(int val) {
   if (isQueueFull() == 1)
       printf("Queue is Full\n");
   else {
       arr[rear] = val;
       rear++;
   }
}
void printQueue() {
   if (isQueueEmpty() == 1) {
       printf("Queue is Empty.\n");
   } else {
       printf("Queue elements: ");
       for (int i = front; i < rear; i++) {
           printf("%d ", arr[i]);
       }
          printf("\n");
   }
}
int main() {
   int choice, value;
   while (1) {
       printf("\nQueue Operations:\n");
       printf("1. Enqueue\n");
       printf("2. Dequeue\n");
       printf("3. Print Queue\n");
       printf("4. Exit\n");
       printf("Enter your choice: ");
       scanf("%d", &choice);
    switch (choice) {
           case 1:
               printf("Enter the value to enqueue: ");
               scanf("%d", &value);
               enqueue(value);
               break;
           case 2:
               dequeue();
               break;
           case 3:
               printQueue();
               break;
           case 4:
               printf("Exited.\n");
               return 0;
           default:
               printf("Invalid choice.\n");
       }
   }
   return 0;
}

