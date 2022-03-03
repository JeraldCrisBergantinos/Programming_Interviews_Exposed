#include <iostream>

using namespace std;

// A singly linked list in C++
class IntElement {
public:
    IntElement(int value) : next(NULL), data(value) {}
    ~IntElement() {}

    IntElement *getNext() const { return next; }
    int value() const { return data; }
    void setNext(IntElement *elem) { next = elem; }
    void setValue(int value) { data = value; }

//private:
    IntElement *next;
    int data;
};

// A templated C++ singly linked list
template <class T>
class ListElement {
public:
    ListElement(const T &value) : next(NULL), data(value) {}
    ~ListElement() {}

    ListElement *getNext() const { return next; }
    const T& value() const { return data; }
    void setNext(ListElement *elem) { next = elem; }
    void setValue(const T &value) { data = value; }

private:
    ListElement *next;
    T data;
};

bool insertInFront(IntElement **head, int data) {
    IntElement *newElem = (IntElement*)malloc(sizeof(IntElement));
    if (!newElem) return false;

    newElem->setValue(data);
    newElem->setNext(*head);
    *head = newElem;
    return true;
}

ListElement<int>* find(ListElement<int> *head, int data) {
    ListElement<int> *elem = head;
    while (elem != NULL && elem->value() != data) {
        elem = elem->getNext();
    }

    return elem;
}

bool deleteElement(IntElement **head, IntElement *deleteMe) {
    IntElement *elem;

    if (!head || !*head || !deleteMe) { // Check for null pointers.
        return false;
    }

    elem = *head;
    if (deleteMe == *head) { // Special case for head
        (*head)->setNext(elem->getNext());
        free(deleteMe);
        return true;
    }

    while (elem) {
        if (elem->getNext() == deleteMe) {
            // elem is the element preceding deleteMe
            elem->setNext(deleteMe->getNext());
            free(deleteMe);
            return true;
        }
        elem = elem->getNext();
    }

    // deleteMe not found.
    return false;
}

bool deleteElement2(IntElement **npp, IntElement *deleteMe) {
    if (!npp || !*npp || !deleteMe) { // Check for null pointers.
        return false;
    }

    while (*npp) {
        if (*npp == deleteMe) {
            // npp points to head pointer (if deleteMe is the first element)
            // or the next pointer within preceding element
            *npp = deleteMe->next;
            free(deleteMe);
            return true;
        }
        npp = &((*npp)->next);
    }

    // deleteMe not found.
    return false;
}

void deleteList(IntElement **head) {
    IntElement *deleteMe = *head;
    while (deleteMe) {
        IntElement *next = deleteMe->getNext();
        free(deleteMe);
        deleteMe = next;
    }

    *head = NULL;
}

void display(IntElement* head) {
    IntElement* elem = head;
    while (elem) {
        cout << elem->value() << endl;
        elem = elem->getNext();
    }
}

int main()
{
    IntElement* ie1 = new IntElement(1);
    IntElement* ie2 = new IntElement(2);
    IntElement* ie3 = new IntElement(3);

    ie1->setNext(ie2);
    ie2->setNext(ie3);

    cout << "Initial" << endl;
    display(ie1);
    cout << "\n";

    cout << "Delete element" << endl;
    deleteElement2(&ie1, ie2);
    display(ie1);
    cout << "\n";

    cout << "Delete list" << endl;
    deleteList(&ie1);
    display(ie1);
    cout << "\n";

    return 0;
}
