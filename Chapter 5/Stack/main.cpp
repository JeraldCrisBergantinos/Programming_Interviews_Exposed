#include <iostream>
#include <exception>

using namespace std;

#define E_EMPTY 13

class StackError : public exception {
public:
    StackError(int _errorCode) : errorCode(_errorCode) {}
    const char* what() const throw() {
        return "Stack Error";
    }

private:
    int errorCode;
};

template <class T>
class Stack {
public:
    Stack() : head(nullptr) {}
    ~Stack();
    void push(T data);
    T pop();
protected:
    class Element {
    public:
        Element(Element *n, T d) : next(n), data(d) {}
        Element *getNext() const { return next; }
        T value() const { return data; }
    private:
        Element *next;
        T data;
    };

    Element *head;
};

template <class T>
Stack<T>::~Stack() {
    while (head) {
        Element *next = head->getNext();
        delete head;
        head = next;
    }
}

template <class T>
void Stack<T>::push(T data) {
    // Allocation error will throw exception
    Element *elem = new Element(head, data);
    head = elem;
}

template <class T>
T Stack<T>::pop() {
    Element *elem = head;
    T data;

    // Assume the StackError exception class is defines somewhere.
    if (head == nullptr) {
        throw StackError(E_EMPTY);
    }

    data = head->value();
    head = head->getNext();
    delete elem;
    return data;
}

int main()
{
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    try {
        while (true) {
            cout << s.pop() << endl;
        }
    } catch (StackError& ex) {}

    return 0;
}
