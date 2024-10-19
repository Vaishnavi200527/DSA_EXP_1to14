#include <stdio.h>
#include <stdlib.h>

// Create a node
struct Node {
    int data;
    struct Node* next;
};

// Insert at the beginning
void insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Insert a node after a node
void insertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("The given previous node cannot be NULL\n");
        return;
    }
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Insert at the end
void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
}

// Delete at the beginning
void deleteAtBeginning(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }
    struct Node* temp = *head_ref;
    *head_ref = temp->next;
    free(temp);
}

// Delete at a specific position
void deleteAtPosition(struct Node** head_ref, int position) {
    if (*head_ref == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }

    struct Node* temp = *head_ref;

    if (position == 0) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range\n");
        return;
    }

    struct Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

// Delete at the end
void deleteAtEnd(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }

    struct Node* temp = *head_ref;
    struct Node* prev = NULL;

    if (temp->next == NULL) {
        *head_ref = NULL;
        free(temp);
        return;
    }

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
}

// Search a node
int searchNode(struct Node** head_ref, int key) {
    struct Node* current = *head_ref;

    while (current != NULL) {
        if (current->data == key)
            return 1;
        current = current->next;
    }
    return 0;
}

// Sort the linked list
void sortLinkedList(struct Node** head_ref) {
    struct Node *current = *head_ref, *index = NULL;
    int temp;

    if (*head_ref == NULL) {
        return;
    } else {
        while (current != NULL) {
            index = current->next;
            while (index != NULL) {
                if (current->data > index->data) {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}

// Print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf(" %d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position, key;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert after a specific position\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at specific position\n");
        printf("6. Delete at end\n");
        printf("7. Search for a node\n");
        printf("8. Sort the list\n");
        printf("9. Print the list\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        struct Node* current = head;

        switch (choice) {
            case 1:
                printf("Enter the value to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter the value to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter the position after which to insert (0 for head): ");
                scanf("%d", &position);
                printf("Enter the value to insert: ");
                scanf("%d", &data);
                for (int i = 0; i < position && current != NULL; i++) {
                    current = current->next;
                }
                if (current == NULL && position != 0) {
                    printf("Invalid position\n");
                } else {
                    insertAfter(current, data);
                }
                break;
            case 4:
                deleteAtBeginning(&head);
                printf("Deleted at beginning\n");
                break;
            case 5:
                printf("Enter the position to delete (0 for head): ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                printf("Deleted at position %d\n", position);
                break;
            case 6:
                deleteAtEnd(&head);
                printf("Deleted at end\n");
                break;
            case 7:
                printf("Enter the value to search: ");
                scanf("%d", &key);
                if (searchNode(&head, key)) {
                    printf("%d is found\n", key);
                } else {
                    printf("%d is not found\n", key);
                }
                break;
            case 8:
                sortLinkedList(&head);
                printf("List sorted\n");
                break;
            case 9:
                printf("Linked list: ");
                printList(head);
                break;
            case 10:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
