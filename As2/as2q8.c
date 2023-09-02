#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int front = -1, rear = -1, queue[MAX];

void insert() {
    int item;
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Queue overflow\n");
        return;
    }
    if (front == -1) {
        front = 0;
        rear = 0;
    } else {
        if (rear == MAX - 1)
            rear = 0;
        else
            rear = rear + 1;
    }
    printf("Enter the item to be inserted: ");
    scanf("%d", &item);
    queue[rear] = item;
}

void delete() {
    int item;
    if (front == -1) {
        printf("Queue underflow\n");
        return;
    }
    item = queue[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        if (front == MAX - 1)
            front = 0;
        else
            front = front + 1;
    }
    printf("Item deleted: %d\n", item);
}

void display() {
    int i;
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    if (rear >= front) {
        for (i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    } else {
        for (i = front; i < MAX; i++)
            printf("%d ", queue[i]);
        for (i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }
}

int num_of_elements() {
    int count;
    if (front == -1)
        return 0;
    if (rear >= front)
        count = rear - front + 1;
    else
        count = MAX - front + rear + 1;
    return count;
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Insert\n");
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
            printf("Number of elements: %d\n", num_of_elements());
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
