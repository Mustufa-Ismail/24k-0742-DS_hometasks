#include <iostream>
using namespace std;

class Node
{
public:
    string name;
    double price;
    Node *next;

    Node() : name(""), price(0), next(nullptr) {};
    Node(string name, double price) : name(name), price(price), next(nullptr) {};
};

class LinkedList
{
public:
    Node *head;

    LinkedList() : head(nullptr) {};
    LinkedList(Node *next) : head(next) {};

    void insertAtEnd(string name, double price)
    {

        Node *nn = new Node(name, price);

        if (head == nullptr)
        {
            head = nn;
            return;
        }
        else if (head->next == nullptr)
        {
            head->next = nn;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = nn;
        return;
    }

    void insertAtFront(string name, double price)
    {

        Node *nn = new Node(name, price);

        nn->next = head;
        head = nn;
    }

    void insertAtvalue(string name, double price, string val)
    {

        Node *nn = new Node(name, price);
        if (head == nullptr)
        {
            cout << "List doesnt exist";
            return;
        }
        bool found = false;
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->name == val)
            {
                found = true;
                break;
            }
            temp = temp->next;
        }

        if (found == false)
        {
            cout << "value not Found";
            return;
        }
        nn->next = temp->next;
        temp->next = nn;
        return;
    }

    void search(string val)
    {
        Node *temp = head;
        if (head == nullptr)
        {
            cout << "List is empty";
            return;
        }
        while (temp != nullptr)
        {
            if (temp->name == val)
            {
                cout << "\nitem exists in the cart" << endl;
                cout << "Name:" << temp->name << endl;
                cout << "Price: $" << temp->price << endl
                     << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Item is not in the cart \n";
        return;
    }

    void diplayList()
    {
        Node *temp = head;
        if (head == nullptr)
        {
            cout << "List is empty";
            return;
        }
        while (temp != nullptr)
        {
            cout << "\nName:" << temp->name << endl;
            cout << "Price: $" << temp->price << endl;
            temp = temp->next;
        }

        return;
    }
};

int main()
{
    Node *n1 = new Node("Laptop", 1000);
    LinkedList l1(n1);
    l1.insertAtEnd("Phone", 700);
    l1.insertAtEnd("Tablet", 400);
    l1.insertAtEnd("Headphones", 150);
    l1.diplayList();

    l1.insertAtFront("Smartwatch", 200);
    l1.insertAtEnd("Keyboard", 80);
    l1.insertAtvalue("Monitor", 300, "Phone");

    l1.search("Tablet");

    cout << "\nAfter adding new items \n";
    l1.diplayList();
}