#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node_s {
    int data;
    struct Node_s *link;
} Node;

Node * xor(Node * next, Node *previous) {
    return (Node *)((uintptr_t)next ^ (uintptr_t)previous);
}

void insert_beginning(Node **head, int data) {
    Node *new = (Node *)malloc(sizeof(Node));
    new->data = data;
    new->link = xor(*head, NULL);
    if (*head) {
        (*head)->link = xor(new, xor((*head)->link, NULL));
    }
    *head = new;
}

void print_list_forward(Node *head) {
    Node *current = head;
    Node *previous = NULL;
    Node *next = NULL;

    while (current) {
        printf("%d", current->data);
        next = xor(previous, current->link);
        if (next) {
            printf(" -> ");
        }
        previous = current;
        current = next;
    }
    printf("\n");
}

void print_list_backward(Node *tail) {
    Node *current = tail;
    Node *previous = NULL;
    Node *next = NULL;

    while (current) {
        printf("%d", current->data);
        previous = xor(current->link, next);
        if (previous) {
            printf(" -> ");
        }
        next = current;
        current = previous;
    }
    printf("\n");
}

void destroy_list(Node *head) {
    Node *current = head;
    Node *previous = NULL;
    Node *next = NULL;

    while (current) {
        next = xor(previous, current->link);
        free(previous);
        previous = current;
        current = next;
    }
    free(previous);
}

int main(void) {
    /* Creating a list */
    Node *head = NULL;
    Node *last = NULL;
    for (int i = 0; i < 10; i++) {
        insert_beginning(&head, i);
        /* Keeping a reference to the tail of the list */
        if (i == 0) {
            last = head;
        }
    }

    printf("FORWARD: \n");
    print_list_forward(head);
    printf("\nBACKWARD: \n");
    print_list_backward(last);

    destroy_list(head);
    return 0;
}
