#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct stack {
    struct node *top;
    int size;
};

struct node* new_node(int data)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

struct stack* create_stack()
{
    struct stack *st = (struct stack*)malloc(sizeof(struct stack));
    st->top = NULL;
    st->size = 0;
    return st;
}

void push(struct stack *st, int data)
{
    struct node *temp = new_node(data);
    temp->next = st->top;
    st->top = temp;
    st->size++;
}

int pop(struct stack *st)
{
    if (st->size == 0) {
        printf("Error: Stack is empty\n");
        return -1;
    }

    int data = st->top->data;
    st->top = st->top->next;
    st->size--;
    return data;
}

int is_empty(struct stack *st)
{
    return (st->size == 0);
}

void print_stack(struct stack *st)
{
    printf("Stack: ");
    struct node *temp = st->top;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct stack *st = create_stack();

    int choice;
    int data;

    while (1) {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Print\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
        case 1:
            printf("Enter data to push: ");
            scanf("%d", &data);
            push(st, data);
            break;
        case 2:
            data = pop(st);
            if (data != -1) {
                printf("Popped data: %d\n", data);
            }
            break;
        case 3:
            print_stack(st);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
