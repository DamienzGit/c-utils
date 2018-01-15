#include "data-structures/linkedlist.h"



int main() {

    node* a = createnode(0);
    for (int i = 1; i < 5; ++i) {
        prepend(a, i);
    }

    display(a);
}