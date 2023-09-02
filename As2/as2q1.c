#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertNode(int data, int position) {
    int i;
    struct node *newNode, *temp;

    newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;

    if (position == 1 || head == NULL) {
        newNode->next = head;
        head = newNode;
        return;
    }

    temp = head;
    for (i = 0; i < position - 2; i++) {
        if (temp->next == NULL) {
            printf("Invalid position\n");
            return;
        }
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteNode(int position) {
    int i;
    struct node *temp, *toBeDeleted;

    if (head == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    if (position == 1) {
        toBeDeleted = head;
        head = head->next;
        free(toBeDeleted);
        return;
    }

    temp = head;
    for (i = 0; i < position - 2; i++) {
        if (temp->next == NULL) {
            printf("Invalid position\n");
            return;
        }
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Invalid position\n");
        return;
    }

    toBeDeleted = temp->next;
    temp->next = temp->next->next;
    free(toBeDeleted);
}

int countNodes() {
    struct node *temp;
    int count = 0;

    temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}



void reverseList() {
    struct node *temp = NULL, *next;

    while (head != NULL) {
        next = head->next;
        head->next = temp;
        temp = head;
        head = next;
    }

    head = temp;
}

void displayList() {
    struct node *temp;

    temp = head;
    if (temp == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    printf("The linked list is: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reversePrint() {
    reverseList();
    displayList();
    reverseList();
}

int main() {
    int choice, data, position;
    printf("Enter 1st data: ");
    scanf("%d", &data);
    insertNode(data, 1);

    while (1) {
        printf("1. Insert node\n");
        printf("2. Delete node\n");
        printf("3. Count number of nodes\n");
        printf("4. Reverse print the linked list\n");
        printf("5. Reverse the linked list\n");
        printf("6. Display the linked list\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &position);
                insertNode(data, position);
                break;
            case 2:
                printf("Enter the position: ");
                scanf("%d", &position);
                deleteNode(position);
                break;
            case 3:
                printf("Number of nodes in the linked list: %d\n", countNodes());
                break;
            case 4:
                reversePrint();
                break;
            case 5:
                reverseList();
                break;
            case 6:
                displayList();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
