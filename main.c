#include "data-structures/linkedlist.h"

int main() {

    node* nodeobj = createnode(0);
    for (int i = 1; i < 5; ++i) {
        push(nodeobj, i);
    }
    display(nodeobj);
    node* rev = reverse(nodeobj);
    printf("reversed:\n");
    display(rev);

    display(rev);
}