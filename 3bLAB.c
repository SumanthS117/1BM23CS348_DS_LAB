#include <stdio.h>
#define MAX 5
int queue[MAX], front = -1, rear = -1;
void insert(int value) {
    if ((rear + 1) % MAX == front) printf("Queue is full\n");
    else {
        if (front == -1) front = 0;
        rear = (rear + 1) % MAX;
        queue[rear] = value;
    }
}
void delete() {
    if (front == -1) printf("Queue is empty\n");
    else {
        printf("Deleted: %d\n", queue[front]);
        if (front == rear) front = rear = -1;
        else front = (front + 1) % MAX;
    }
}
void display() {
    if (front == -1) printf("Queue is empty\n");
    else {
        int i = front;
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX;
        }
        printf("%d\n", queue[rear]);
    }
}
int main() {
    int choice, value;
    while (1) {
        printf("1. Insert 2. Delete 3. Display 4. Exit ");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
