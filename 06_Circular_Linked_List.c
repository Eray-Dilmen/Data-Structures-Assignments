#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


void traverse(struct Node* head) {
    struct Node* temp = head;
    if (head != NULL) {
        printf("\nCircular List: ");
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    } else {
        printf("\nList is empty.\n");
    }
}


void insertAfter(struct Node* head, int target_val, int new_val) {
    if (head == NULL) return;

    struct Node *temp = head;
    struct Node *p;


    do {
        if (temp->data == target_val) {
            p = temp;
            break;
        }
        temp = temp->next;
    } while (temp != head);

    if (temp == head && temp->data != target_val) {
        printf("Target value %d not found in the list.\n", target_val);
        return;
    }


    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_val;


    new_node->next = p->next;
    p->next = new_node;
}


void deleteNode(struct Node** head, int key) {
    if (*head == NULL) return;

    struct Node *curr = *head, *prev;

    if ((*head)->next == *head && (*head)->data == key) {
        free(*head);
        *head = NULL;
        return;
    }


    if ((*head)->data == key) {

        prev = *head;
        while (prev->next != *head)
            prev = prev->next;


        prev->next = (*head)->next;
        free(*head);
        *head = prev->next;
        return;
    }


    while (curr->next != *head && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }


    if (curr->data == key) {
        prev->next = curr->next;
        free(curr);
    } else {
        printf("Node with value %d not found.\n", key);
    }
}


void insertAtBegin(struct Node** head, int data) {
    struct Node *ptr1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = *head;
    ptr1->data = data;
    ptr1->next = *head;


    if (*head != NULL) {
        while (temp->next != *head)
            temp = temp->next;
        temp->next = ptr1;
    } else {
        ptr1->next = ptr1;
    }

    *head = ptr1;
}

int main() {

		/// HW 6: Circular linked list deletion code, insertion, traversal




    struct Node *head = NULL;
   	insertAtBegin(&head, 5); insertAtBegin(&head, 8); insertAtBegin(&head, 10);

    printf("Original List:");
    traverse(head);

    printf("\nInserting 20 after 8");
    insertAfter(head, 8, 20);
    traverse(head);

    printf("\nDeleting 10 (Head)");
    deleteNode(&head, 10);
    traverse(head);

    printf("\nDeleting 20 (Middle)");
    deleteNode(&head, 20);
    traverse(head);

    return 0;
}