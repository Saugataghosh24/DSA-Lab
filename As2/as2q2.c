#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *create_node(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    return node;
}

Node *create_circular_linked_list(int num_people) {
    Node *head, *curr;

    for (int i = 1; i <= num_people; i++) {
        Node *node = create_node(i);

        if (i == 1) {
            head = node;
            curr = node;
            curr->next = head;
        } else {
            curr->next = node;
            curr = node;
            curr->next = head;
        }
    }

    return head;
}

void solve_josephus_problem(int num_people, int kill_every) {
    Node *head = create_circular_linked_list(num_people);
    Node *curr = head;

    while (curr->next != curr) {
        for (int i = 1; i < kill_every+1; i++) {
            curr = curr->next;
        }

        printf("Person %d Eliminated\n", curr->next->data);
        Node *temp = curr->next;
        curr->next = temp->next;
        free(temp);
    }

    printf("SURVIVOR: %d\n", curr->data);
}

int main() {
    int num_people, kill_every;
    printf("Enter the number of people: ");
    scanf("%d", &num_people);
    printf("Enter the number of people to skip before killing: ");
    scanf("%d", &kill_every);
    solve_josephus_problem(num_people, kill_every);
    return 0;
}
