#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

/* Utility function to count nodes */
int countNodes() {
    if (head == NULL)
        return 0;

    int count = 1;
    struct Node *temp = head;
    while (temp->next != head) {
        count++;
        temp = temp->next;
    }
    return count;
}

/* Create CLL */
void createCLL() {
    int n, i, val;
    struct Node *temp, *newNode;

    printf("How many nodes? ");
    scanf("%d", &n);

    if (n <= 0)
        return;

    head = NULL;

    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = val;

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            temp = head;
        } else {
            temp->next = newNode;
            newNode->next = head;
            temp = newNode;
        }
    }
}

/* Insert at position */
void insertAtPosition() {
    int pos, val, i;
    struct Node *newNode, *temp;

    printf("Position: ");
    scanf("%d", &pos);
    printf("Element: ");
    scanf("%d", &val);

    int n = countNodes();
    if (pos < 1 || pos > n + 1) {
        printf("Position not found\n");
        return;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;

    if (pos == 1) {
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            temp = head;
            while (temp->next != head)
                temp = temp->next;

            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
    } else {
        temp = head;
        for (i = 1; i < pos - 1; i++)
            temp = temp->next;

        newNode->next = temp->next;
        temp->next = newNode;
    }
}

/* Delete at position */
void deleteAtPosition() {
    if (head == NULL) {
        printf("CLL is empty\n");
        return;
    }

    int pos, i;
    printf("Position: ");
    scanf("%d", &pos);

    int n = countNodes();
    if (pos < 1 || pos > n) {
        printf("Position not found\n");
        return;
    }

    struct Node *temp = head, *prev;

    if (pos == 1) {
        if (head->next == head) {
            printf("Deleted element: %d\n", head->data);
            free(head);
            head = NULL;
            return;
        }

        prev = head;
        while (prev->next != head)
            prev = prev->next;

        prev->next = head->next;
        printf("Deleted element: %d\n", head->data);
        free(head);
        head = prev->next;
    } else {
        for (i = 1; i < pos; i++) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        printf("Deleted element: %d\n", temp->data);
        free(temp);
    }
}

/* Display CLL */
void displayCLL() {
    if (head == NULL) {
        printf("CLL is empty\n");
        return;
    }

    struct Node *temp = head;
    printf("Elements in CLL are: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

/* Reverse CLL */
void reverseCLL() {
    if (head == NULL) {
        printf("CLL is empty\n");
        return;
    }

    struct Node *prev = NULL, *current = head, *nextNode;
    struct Node *last = head;

    do {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    } while (current != head);

    head->next = prev;
    head = prev;

    printf("CLL reversed\n");

    struct Node *temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

/* Concatenate two CLLs */
void concatenateCLL() {
    int n, i, val;
    struct Node *head2 = NULL, *temp2, *newNode;

    printf("Creating second CLL to concatenate...\n");
    printf("How many nodes in second CLL? ");
    scanf("%d", &n);

    if (n <= 0)
        return;

    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = val;

        if (head2 == NULL) {
            head2 = newNode;
            newNode->next = head2;
            temp2 = head2;
        } else {
            temp2->next = newNode;
            newNode->next = head2;
            temp2 = newNode;
        }
    }

    if (head == NULL) {
        head = head2;
    } else {
        struct Node *temp1 = head;
        while (temp1->next != head)
            temp1 = temp1->next;

        temp1->next = head2;

        temp2 = head2;
        while (temp2->next != head2)
            temp2 = temp2->next;

        temp2->next = head;
    }

    printf("Concatenated CLL:\n");
    struct Node *temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

/* Main */
int main() {
    int choice;

    do {
        printf("1.Create 2.Insert 3.Delete 4.Display 5.Reverse 6.Concat 7.Exit\n");
        printf("choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            createCLL();
            break;
        case 2:
            insertAtPosition();
            break;
        case 3:
            deleteAtPosition();
            break;
        case 4:
            displayCLL();
            break;
        case 5:
            reverseCLL();
            break;
        case 6:
            concatenateCLL();
            break;
        case 7:
            break;
        default:
            break;
        }
    } while (choice != 7);

    return 0;
}
