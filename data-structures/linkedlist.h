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


void swap(node** a, node** b) {
    node* temp = *a;
    *a = *b;
    *b = temp;
}
node* createnode(int init) {
    node* n = malloc(nodesize);
    n->h = init;
    n->next = NULL;
    n->size = 1;
    return n;
}
void push(node* n, int num) {
    if (n->size == 0) {
        n->h = num;
        n->next = NULL;
        n->size = 1;
    }
    node* copy = n;
    while (copy->next != NULL) {
        copy = copy->next;
        copy->size += 1;
    }
    node* newnode = createnode(num);
    copy->next = newnode;
    n->size += 1;
}
void prepend(node* n, int num) {
    if (n->size == 0) {
        n->h = num;
        n->next = NULL;
        n->size = 1;
        return;
    }
    node* new_ = createnode(num);
    new_->next = n;
    new_->size = n->size + 1;
    swap(&n, &new_);
}
int pop(node* n) {
    if (n->size == 0) {
        printf("ERROR: Empty Node, returning NULL\n");
        return NULL;
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
node* reverse(node* n) {
    node *copy = n;
    int size = n->size;

    if (size == 0 || size == 1) { return NULL; }

    node* new_ = createnode(n->h);
    copy = n->next;
    n = NULL;
    while(copy->next) {
        prepend(new_, copy->h);
        node* current = copy;
        copy = copy->next;
        current = NULL;
        free(current);
    }
    prepend(new_, copy->h);
    node* current = copy;
    copy = copy->next;
    current = NULL;
    free(current);
    return new_;
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
int remove_node(node* n, int num) {
    int s = n->size;
    if ( s == 0) {
        return NULL;
    }
    if (s == 1 && n->h != num) {
        return NULL;
    }
    if (s == 1 && n->h == num ) {
        int ret = n->h;
        n->next = NULL;
        n->size = 0;
        return ret;
    }
    if (num == n->h) {
        int ret = n->h;
        n->h = n->next->h;
        n->next = n->next->next;
        n->size -= 1;
        return ret;
    }


    while (n->next) {
        if (n->next->h == num) {
            int ret = n->next->h;
            n->size -= 1;
            n->next = n->next->next;
            free(n->next);
            return ret;
        } else {
            n->size -= 1;
            n = n->next;
        }
    }
    // check if the n pointer is at the last node
    if (n->size == 1) {
        if (n->h == num) {
            return remove_node(n, num);
        }
        else {
            return NULL;
        }
    }
}