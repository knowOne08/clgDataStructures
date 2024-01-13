#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to print the circular linked list
void printList(struct Node* head) {
    if (head == NULL) {
        printf("Circular Linked List is empty.\n");
        return;
    }

    struct Node* current = head;
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);

    printf("(head)\n");
}

// Function to insert a node at the front of the circular linked list
void insertAtFront(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        struct Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        newNode->next = *head;
        last->next = newNode;
        *head = newNode;
    }

    printf("Node with value %d inserted at the front.\n", value);
}

// Function to insert a node at the end of the circular linked list
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        struct Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        newNode->next = *head;
        last->next = newNode;
    }

    printf("Node with value %d inserted at the end.\n", value);
}

// Function to insert a node at a specific position in the circular linked list
void insertAtPosition(struct Node** head, int value, int position) {
    if (position < 1) {
        printf("Invalid position! Position should be 1 or greater.\n");
        return;
    }

    struct Node* newNode = createNode(value);

    if (position == 1) {
        if (*head == NULL) {
            *head = newNode;
            newNode->next = *head;
        } else {
            struct Node* last = *head;
            while (last->next != *head) {
                last = last->next;
            }
            newNode->next = *head;
            last->next = newNode;
            *head = newNode;
        }

        printf("Node with value %d inserted at position %d.\n", value, position);
        return;
    }

    struct Node* current = *head;
    for (int i = 1; i < position - 1 && current->next != *head; i++) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;

    printf("Node with value %d inserted at position %d.\n", value, position);
}

// Function to delete the last node in the circular linked list
void deleteLastNode(struct Node** head) {
    if (*head == NULL) {
        printf("Circular Linked List is empty. Cannot delete from an empty list.\n");
        return;
    }

    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
        printf("Last node deleted.\n");
        return;
    }

    struct Node* current = *head;
    struct Node* previous = NULL;

    while (current->next != *head) {
        previous = current;
        current = current->next;
    }

    previous->next = current->next;
    free(current);

    printf("Last node deleted.\n");
}

// Function to delete a node before or after a specified position
void deleteNodeAtPosition(struct Node** head, int position, int isBefore) {
    if (*head == NULL) {
        printf("Circular Linked List is empty. Cannot delete from an empty list.\n");
        return;
    }

    if (position < 1) {
        printf("Invalid position! Position should be 1 or greater.\n");
        return;
    }

    struct Node* current = *head;
    struct Node* previous = NULL;

    if (position == 1) {
        if ((*head)->next == *head) {
            free(*head);
            *head = NULL;
            printf("Node deleted at position %d.\n", position);
            return;
        }

        while (current->next != *head) {
            previous = current;
            current = current->next;
        }

        previous->next = current->next;
        free(current);
        *head = previous->next;

        printf("Node deleted at position %d.\n", position);
        return;
    }

    for (int i = 1; i < position && current->next != *head; i++) {
        previous = current;
        current = current->next;
    }

    if (current == *head) {
        printf("Invalid position! Position exceeds the length of the circular linked list.\n");
        return;
    }

    if (isBefore) {
        previous->next = current->next;
        free(current);
    } else {
        struct Node* temp = current->next;
        current->next = temp->next;
        free(temp);
    }

    printf("Node deleted %s position %d.\n", (isBefore ? "before" : "after"), position);
}


int main() {
    struct Node* head = NULL;

    insertAtFront(&head, 5);
    insertAtFront(&head, 3);
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 15);
    insertAtPosition(&head, 8, 3);

    printList(head);

    deleteLastNode(&head);
    printList(head);

    deleteNodeAtPosition(&head, 2, 1); // Delete before position 2
    printList(head);

    deleteNodeAtPosition(&head, 4, 0); // Delete after position 4
    printList(head);

    freeList(&head);

    return 0;
}
