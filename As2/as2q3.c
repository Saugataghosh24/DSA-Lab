#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

void insertNode(int data, int position);
void deleteNode(int position);
int countNodes();
void reversePrint();
void reverseList();
void displayList();

int main() {
    int choice, data, position;
    printf("Enter 1st data: ");
    scanf("%d", &data);
    insertNode(data, 1);

    while (1) {
        printf("Choose one of the following operations:\n");
        printf("1. Insert a node at a specified position\n");
        printf("2. Delete a node from a specified position\n");
        printf("3. Count the number of nodes in the linked list\n");
        printf("4. Reverse print the linked list\n");
        printf("5. Reverse the linked list\n");
        printf("6. Display the linked list\n");
        printf("7. Quit\n");

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
                printf("The number of nodes in the linked list is: %d\n", countNodes());
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
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}

void insertNode(int data, int position) {
    struct node *newNode, *temp;
    int i;

    if (position < 1 || position > countNodes() + 1) {
        printf("Invalid position\n");
        return;
    }

    newNode = (struct node *) malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation error\n");
        return;
    }
    newNode->data = data;

    if (position == 1) {
        newNode->prev = NULL;
        newNode->next = head;
        if (head != NULL)
            head->prev = newNode;
        head = newNode;
        return;
    }

    temp = head;
    for (i = 0; i < position - 2; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteNode(int position) {
struct node *temp, *toBeDeleted;
int i;
if (position < 1 || position > countNodes()) {
    printf("Invalid position\n");
    return;
}

if (position == 1) {
    toBeDeleted = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    free(toBeDeleted);
    return;
}

temp = head;
for (i = 0; i < position - 2; i++) {
    temp = temp->next;
}

toBeDeleted = temp->next;
temp->next = temp->next->next;
if (temp->next != NULL)
    temp->next->prev = temp;
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

void reversePrint() {
struct node *temp;
temp = head;
while (temp->next != NULL) {
    temp = temp->next;
}

printf("The linked list in reverse order is: ");
while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->prev;
}
printf("\n");
}

void reverseList() {
struct node *temp, *current;
current = head;
temp = NULL;
while (current != NULL) {
    temp = current->prev;
    current->prev = current->next;
    current->next = temp;
    current = current->prev;
}

if (temp != NULL)
    head = temp->prev;
}

void displayList() {
struct node *temp;
temp = head;
printf("The linked list is: ");
while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
}
printf("\n");
}
