// Author: Damiano Di Natale
// Date: 2018-1-15


#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int h;
    int size;
    struct node* next;
} node;

const int nodesize = sizeof(node);

node* createnode(int init);
int pop(node* n);
void push(node* n, int num);
void display(node* n);

node* createnode(int init) {
    node* n = malloc(nodesize);
    n->h = init;
    n->next = NULL;
    n->size = 1;
    return n;
}

void push(node* n, int num) {
    node* copy = n;
    while (copy->next != NULL) {
        copy = copy->next;
        copy->size += 1;
    }
    node* newnode = createnode(num);
    copy->next = newnode;
    n->size += 1;
}

int pop(node* n) {
    if (n->size == 0) {
        printf("ERROR: Empty Node, returning -100 Error Code\n");
        return -100;
    }
    if (n->size == 1) {
        int ret = n->h;
        n->size = 0;
        n->h = NULL;
        n->next = NULL;
        return ret;
    }
    if (n->size == 2) {
        n->size-= 1;
    }
    node* copy = n;
    while (copy->next->next) {
        copy->size -= 1;
        copy = copy->next;

    }
    int ret = copy->next->h;
    copy->next = NULL;
    return ret;
}

void display(node* n) {
    int initialsize = n->size;
    if (initialsize == 0) {
        return;
    }
    if (initialsize == 1) {
        printf("%d\n", n->h);
        printf("total size: %d\n", initialsize);
        return;
    }
    while (n->next != NULL) {
        printf("%d ", n->h);
        n = n->next;
    }
    printf("%d\n", n->h);
    printf("total size: %d\n", initialsize);
}