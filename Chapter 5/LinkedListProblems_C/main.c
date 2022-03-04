#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Element {
    struct Element *next;
    void *data;
} Element;

bool push(Element **stack, void *data);
bool pop(Element **stack, void **data);

bool createStack(Element **stack);
bool deleteStack(Element **stack);

bool createStack(Element **stack) {
    *stack = NULL;
    return true;
}

bool push(Element **stack, void *data) {
    Element *elem = malloc(sizeof(Element));
    if (!elem) return false;

    elem->data = data;
    elem->next = *stack;
    *stack = elem;
    return true;
}

bool pop(Element **stack, void **data) {
    Element *elem;
    if (!(elem = *stack)) return false;

    *data = elem->data;
    *stack = elem->next;
    free(elem);
    return true;
}

bool deleteStack(Element **stack) {
    Element *next;
    while (*stack) {
        next = (*stack)->next;
        free(*stack);
        *stack = next;
    }
    return true;
}

void display(Element *stack) {
    while (stack) {
        printf("%d\n", *((int*)(stack->data)));
        stack = stack->next;
    }
}

int main()
{
    Element *stack;
    createStack(&stack);

    int n1 = 1, n2 = 2, n3 = 3;
    push(&stack, &n1);
    push(&stack, &n2);
    push(&stack, &n3);
    display(stack);
    printf("\n");

    int *popElem;
    pop(&stack, (void*)(&popElem));
    display(stack);
    printf("\n");
    printf("Popped %d", *popElem);
    printf("\n");

    deleteStack(&stack);
    display(stack);

    return 0;
}
