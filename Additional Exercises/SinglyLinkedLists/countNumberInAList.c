#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0

typedef int data_t;
typedef struct _node {
    data_t data;
    struct _node *next;
}Node;

int createALinkedList(Node **head);
int printList(Node *head);
int count(Node *head, data_t data);

int main() {
    // create a linked list
    Node *head = NULL;
    createALinkedList(&head);
    printList(head);
    
    printf("count of 3: %d\n", count(head, 3));
    return SUCCESS;
}

int printList(Node *head) {
    while(head) {
        printf("%d->", head->data);
        head = head->next;
    }
    puts("NULL");
    putc('\n', stdout);
}

int createALinkedList(Node **head) {
    int i = 0;
    (*head) = (Node *)malloc(sizeof(Node));
    Node *temp = *head;
    while(i < 9) {
        (temp)->data = i++;
        (temp)->next = (Node *)malloc(sizeof(Node));
        temp = temp->next;
    }
    temp->data = i;
    temp->next = NULL;

    return SUCCESS;
}

int count(Node *head, data_t data) {
    int count = 0;

    while(head) {
        if(head->data == data)
            ++count;
        head = head->next;
    }

    return count;
}