#include <stdio.h>
#include <stdlib.h>

// Node structure for Doubly Linked List
struct Node {
    int data;
    struct Node* prev;
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
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the front of the Doubly Linked List
void insertAtFront(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;

    printf("Node with value %d inserted at the front.\n", value);
}

// Function to insert a node at the end of the Doubly Linked List
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    struct Node* last = *head;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
    newNode->prev = last;

    printf("Node with value %d inserted at the end.\n", value);
}

// Function to insert a node at a specific position in the Doubly Linked List
void insertAtPosition(struct Node** head, int value, int position) {
    if (position < 1) {
        printf("Invalid position! Position should be 1 or greater.\n");
        return;
    }

    if (position == 1) {
        insertAtFront(head, value);
        return;
    }

    struct Node* newNode = createNode(value);
    struct Node* current = *head;

    for (int i = 1; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Invalid position! Position exceeds the length of the Doubly Linked List.\n");
        return;
    }

    newNode->next = current->next;
    newNode->prev = current;
    
    if (current->next != NULL) {
        current->next->prev = newNode;
    }

    current->next = newNode;

    printf("Node with value %d inserted at position %d.\n", value, position);
}

// Function to delete the last node in the Doubly Linked List
void deleteLastNode(struct Node** head) {
    if (*head == NULL) {
        printf("Doubly Linked List is empty. Cannot delete from an empty list.\n");
        return;
    }

    struct Node* last = *head;

    while (last->next != NULL) {
        last = last->next;
    }

    if (last->prev != NULL) {
        last->prev->next = NULL;
    } else {
        *head = NULL;
    }

    free(last);

    printf("Last node deleted.\n");
}

// Function to delete a node before or after a specified position
void deleteNodeAtPosition(struct Node** head, int position, int isBefore) {
    if (*head == NULL) {
        printf("Doubly Linked List is empty. Cannot delete from an empty list.\n");
        return;
    }

    if (position < 1) {
        printf("Invalid position! Position should be 1 or greater.\n");
        return;
    }

    if (position == 1) {
        printf("Cannot delete before or after the first position. Use deleteLastNode() to delete the last node.\n");
        return;
    }

    struct Node* current = *head;

    for (int i = 1; i < position && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Invalid position! Position exceeds the length of the Doubly Linked List.\n");
        return;
    }

    if (isBefore && current->prev != NULL) {
        current->prev->next = current->next;
        if (current->next != NULL) {
            current->next->prev = current->prev;
        }
        free(current);
        printf("Node deleted before position %d.\n", position);
    } else if (!isBefore && current->next != NULL) {
        current->next->prev = current->prev;
        if (current->prev != NULL) {
            current->prev->next = current->next;
        } else {
            *head = current->next;
        }
        free(current);
        printf("Node deleted after position %d.\n", position);
    } else {
        printf("Invalid operation! Cannot delete before or after the last position.\n");
    }
}

// Function to print the Doubly Linked List
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    insertAtFront(&head, 5);
    insertAtFront(&head, 3);
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 15);
    insertAtPosition(&head, 8, 3);

    printf("Doubly Linked List: ");
    printList(head);

    deleteLastNode(&head);
    printf("Doubly Linked List after deleting last node: ");
    printList(head);

    deleteNodeAtPosition(&head, 2, 1);
    printf("Doubly Linked List after deleting node before position 2: ");
    printList(head);

    deleteNodeAtPosition(&head, 4, 0); 
    printf("Doubly Linked List after deleting node after position 4: ");
    printList(head);

    freeList(&head);

    return 0;
}
