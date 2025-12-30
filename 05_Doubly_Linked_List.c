#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};


void traverse(struct Node* node) {
    struct Node* last;
    printf("\nTraversal in Forward direction:\n");
    while (node != NULL) {
        printf("%d ", node->data);
        last = node;
        node = node->next;
    }
    printf("\n");
}



void insertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("The given previous node cannot be NULL");
        return;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;
    if (new_node->next != NULL) {
        new_node->next->prev = new_node;
    }
}




void deleteNode(struct Node** head_ref, struct Node* del) {

    if (*head_ref == NULL || del == NULL) {
        return;
    }

    if (*head_ref == del) {
        *head_ref = del->next;
    }

    if (del->next != NULL) {
        del->next->prev = del->prev;
    }

    if (del->prev != NULL) {
        del->prev->next = del->next;
    }
    free(del);
}




void insertAtHead(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    new_node->prev = NULL;
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
    *head_ref = new_node;
}



int main() {


		/// HW 5: Double-linked list deletion, insertion, traversal code.



    struct Node* head = NULL;
    insertAtHead(&head, 30); insertAtHead(&head, 20); insertAtHead(&head, 10);

    printf("Original List:");
    traverse(head);

    printf("\nInserting 25 after 20");
    insertAfter(head->next, 25);
    traverse(head);

    printf("\nDeleting node 20");
    deleteNode(&head, head->next);
    traverse(head);

    return 0;
}