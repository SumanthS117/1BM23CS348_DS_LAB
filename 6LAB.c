#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;
struct Node* head2 = NULL;

void createLinkedList(struct Node** head, int n) {
    int data, i;
    struct Node *newNode, *temp;

    if (n <= 0) return;

    *head = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data for node 1: ");
    scanf("%d", &data);
    (*head)->data = data;
    (*head)->next = NULL;
    temp = *head;

    for (i = 2; i <= n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;
        temp->next = newNode;
        temp = temp->next;
    }
}

void sortLinkedList(struct Node* head) {
    struct Node *i, *j;
    int tempData;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                tempData = i->data;
                i->data = j->data;
                j->data = tempData;
            }
        }
    }
}

void reverseLinkedList(struct Node** head) {
    struct Node *prev = NULL, *current = *head, *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void concatenateLinkedLists(struct Node** head1, struct Node* head2) {
    struct Node *temp = *head1;

    if (*head1 == NULL) {
        *head1 = head2;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
}

void displayList(struct Node* head) {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int n, choice, m;

    printf("Enter number of nodes for the first linked list: ");
    scanf("%d", &n);
    createLinkedList(&head, n);

    while (1) {
        printf("\nMenu: 1. Sort linked list 2. Reverse linked list 3. Concatenate another linked list 4. Display linked list 5. Exit");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                sortLinkedList(head);
                printf("Sorted list: ");
                displayList(head);
                break;
            case 2:
                reverseLinkedList(&head);
                printf("Reversed list: ");
                displayList(head);
                break;
            case 3:
                printf("Enter number of nodes for the second linked list: ");
                scanf("%d", &m);
                createLinkedList(&head2, m);
                concatenateLinkedLists(&head, head2);
                printf("Concatenated list: ");
                displayList(head);
                break;
            case 4:
                displayList(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
