#include <iostream>
using namespace std;

class stack
{
public:
    int Top;
    string arr[100];

    stack() : Top(-1) {}

    void push(string x)
    {
        if (isFull())
        {
            cout << "Stack overflow";
            return;
        }
        Top++;
        arr[Top] = x;
    }

    string pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow";
            return "";
        }
        return arr[Top--];
    }

    string top()
    {
        if (isEmpty())
        {
            cout << "Stack underflow";
            return "";
        }
        return arr[Top];
    }

    bool isEmpty()
    {
        return (Top < 0);
    }

    bool isFull()
    {
        return (Top >= 99);
    }
};

class Node
{
public:
    string name;
    Node *next;

    Node() : name(""), next(nullptr) {}
    Node(string name) : name(name), next(nullptr) {}
};

class LinkedList
{
public:
    Node *head;

    LinkedList() : head(nullptr) {};
    LinkedList(Node *next) : head(next) {};

    void insertAtFront(string name)
    {

        Node *nn = new Node(name);

        nn->next = head;
        head = nn;
    }

    void deleteAtFront()
    {
        if (head == nullptr)
        {
            cout << "List does not exist\n";
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }
};

class browser
{
public:
    LinkedList ll;
    stack ss;

    void visit(string url)
    {
        ll.insertAtFront(url);
        ss.push(url);
    }

    string back()
    {
        ll.deleteAtFront();
        string url = ss.pop();
        return url;
    }

    string current()
    {
        return ss.top();
    }
};

int main()
{
    browser b;
    b.visit("Google");
    b.visit("Facebook");
    b.visit("Linkedin");
    b.visit("Twitter");

    cout << "Current: " << b.current() << endl;

    cout << "Backing 2 sites" << endl;
    b.back();
    b.back();

    cout << "Current: " << b.current() << endl;

    return 0;
}
