#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
    printf("Node with value %d inserted at the beginning.\n", value);
}

void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        printf("Node with value %d inserted at the beginning (as the list was empty).\n", value);
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        printf("Node with value %d inserted at the end.\n", value);
    }
}

void deleteNode(struct Node** head, int value) {
    struct Node* temp = *head;
    struct Node* prev = NULL;
    if (temp != NULL && temp->data == value) {
        *head = temp->next;
        free(temp);
        printf("Node with value %d deleted.\n", value);
        return;
    }
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node with value %d not found.\n", value);
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Node with value %d deleted.\n", value);
}

void traverseList(struct Node* head) {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    printf("Inserting nodes at the beginning and end...\n");

    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtBeginning(&head, 5);

    traverseList(head);
    printf("\n");

    printf("Deleting node with value 20...\n");
    deleteNode(&head, 20);
    traverseList(head);
    printf("\n");

    printf("Deleting node with value 50 (not present)...\n");
    deleteNode(&head, 50);
    traverseList(head);
    printf("\n");

    printf("Inserting node at the end...\n");
    insertAtEnd(&head, 40);
    traverseList(head);
    printf("\n");

    return 0;
}
