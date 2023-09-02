#include <stdio.h>
#define MAX 5

int front = -1, rear = -1, queue[MAX];

void insert() {
    int item;
    if (rear == MAX - 1) {
        printf("Queue overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    printf("Enter the item to be inserted: ");
    scanf("%d", &item);
    rear++;
    queue[rear] = item;
    printf("Item inserted\n");
}

void delete() {
    if (front == -1) {
        printf("Queue underflow\n");
        return;
    }
    printf("Deleted item: %d\n", queue[front]);
    front++;
    if (front > rear)
        front = rear = -1;
}

void display() {
    int i;
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

void num_of_elements() {
    if (front == -1){
        printf("Number of elements: 0\n");
    }
    else
    printf("Number of elements: %d\n", rear - front + 1);
}

int main() {
    int choice;
    while (1) {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Number of elements\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                num_of_elements();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
