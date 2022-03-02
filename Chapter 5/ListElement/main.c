#include <stdio.h>
#include <stdlib.h>

// The simplest singly linked list element
typedef struct ListElement {
    struct ListElement *next;
} ListElement;

// A more useful singly linked list element
typedef struct IntElement {
    struct IntElement *next;
    int data;
} IntElement;

int main()
{
    printf("Hello world!\n");
    return 0;
}
