#include <stdio.h>

void printMessage(void) {
    printf("Hello! The function was called through a pointer in the structure.\n");
}

struct Action {
    void (*actionFunc)(void);
};

int main(void) {
    struct Action myAction;
    myAction.actionFunc = printMessage;
    myAction.actionFunc();
    return 0;
}
