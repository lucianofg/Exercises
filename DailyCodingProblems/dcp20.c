/* Given two singly linked list that intersect at some point, find the
 * intersecting node. The list are non-cyclical.  Ex: A: 3 -> 7 -> 8 -> 10
 * and B: 99 -> 1 -> 8 -> 10 should return the node with value 8. (assume
 * nodes with the same value are the exact same node objects */
#include <stdio.h>

typedef struct Node_s {
    int data;
    struct Node_s *next;
} Node;

Node *find_intersecting_node(Node *head_a, Node *head_b) {
    Node *node_a = head_a;
    while (node_a) {
        Node *node_b = head_b;
        while (node_b) {
            if (node_a == node_b)
                return node_a;
            else
                node_b = node_b->next;
        }
        node_a = node_a->next;
    }
    return NULL;
}

int main(void) {
    /* Building the following lists for test purposes:
     * A: 3  -> 7 -> 8 -> 10
     * B: 99 -> 1 -> 8 -> 10 */
    Node next_a3 = { .data = 10, .next = NULL     };
    Node next_a2 = { .data = 8,  .next = &next_a3 };
    Node next_a1 = { .data = 7,  .next = &next_a2 };
    Node head_a  = { .data = 3,  .next = &next_a1 };
    Node next_b1 = { .data = 1,  .next = &next_a2 };
    Node head_b  = { .data = 99, .next = &next_b1 };

    Node *result = find_intersecting_node(&head_a, &head_b);

    if (result)
        printf("VALUE: %d\t", result->data);

    printf("ADDRESS:%p\n", (void *)result);


    return 0;
}
