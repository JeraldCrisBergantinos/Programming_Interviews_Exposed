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

private:
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

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
