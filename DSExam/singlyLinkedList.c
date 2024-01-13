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

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to insert a node at the front of the linked list
void insertAtFront(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
    printf("Node with value %d inserted at the front.\n", value);
}

// Function to insert a node at the end of the linked list
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    printf("Node with value %d inserted at the end.\n", value);
}

// Function to insert a node at a specific position in the linked list
void insertAtPosition(struct Node** head, int value, int position) {
    if (position < 1) {
        printf("Invalid position! Position should be 1 or greater.\n");
        return;
    }

    struct Node* newNode = createNode(value);

    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        printf("Node with value %d inserted at position %d.\n", value, position);
        return;
    }

    struct Node* current = *head;
    for (int i = 1; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Invalid position! Position exceeds the length of the linked list.\n");
        return;
    }

    newNode->next = current->next;
    current->next = newNode;

    printf("Node with value %d inserted at position %d.\n", value, position);
}

// Function to delete the last node in the linked list
void deleteLastNode(struct Node** head) {
    if (*head == NULL) {
        printf("Linked list is empty. Cannot delete from an empty list.\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        printf("Last node deleted.\n");
        return;
    }

    struct Node* current = *head;
    struct Node* previous = NULL;

    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }

    free(current);
    previous->next = NULL;

    printf("Last node deleted.\n");
}

// Function to delete a node before or after a specified position
void deleteNodeAtPosition(struct Node** head, int position, int isBefore) {
    if (*head == NULL) {
        printf("Linked list is empty. Cannot delete from an empty list.\n");
        return;
    }

    if (position < 1) {
        printf("Invalid position! Position should be 1 or greater.\n");
        return;
    }

    struct Node* current = *head;
    struct Node* previous = NULL;

    if (position == 1) {
        printf("Invalid position! Cannot delete before or after the first node.\n");
        return;
    }

    for (int i = 1; i < position && current != NULL; i++) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Invalid position! Position exceeds the length of the linked list.\n");
        return;
    }

    if (isBefore) {
        if (previous == NULL) {
            printf("Invalid operation! Cannot delete before the first node.\n");
            return;
        }
        previous->next = current->next;
    } else {
        if (current->next == NULL) {
            printf("Invalid operation! Cannot delete after the last node.\n");
            return;
        }
        previous = current->next;
        current->next = current->next->next;
        free(previous);
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

    deleteNodeAtPosition(&head, 2, 1); 
    printList(head);

    deleteNodeAtPosition(&head, 4, 0); 
    printList(head);

    freeList(&head);

    return 0;
}
