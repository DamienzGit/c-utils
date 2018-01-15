#include <stdio.h>
#include "linkedlist.h"

int main() {

    node* nodeobj = createnode(1);
    for (int i=2; i<=5; i++) {
        push(nodeobj, i);
        display(nodeobj)
    }
    for (int i = 0; i<5; i++) {
        pop(nodeobj);
        display(nodeobj);
    }

}