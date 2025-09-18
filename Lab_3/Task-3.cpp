#include <iostream>
using namespace std;

class Node
{
public:
    int id;
    string name;
    double price;
    Node *next;
    Node *prev;

    Node() : id(0), name(""), price(0), next(nullptr), prev(nullptr) {};
    Node(int id, string name, double price) : id(id), name(name), price(price), next(nullptr), prev(nullptr) {};
};

class LinkedList
{
public:
    Node *head;
    Node *tail;

    LinkedList() : head(nullptr), tail(nullptr) {};
    LinkedList(Node *next) : head(next), tail(next) {};

    void insertAtTail(int id, string name, double price)
    {

        Node *nn = new Node(id, name, price);

        if (head == nullptr)
        {
            head = nn;
            tail = nn;
            return;
        }

        nn->prev = tail;
        tail->next = nn;
        tail = nn;
        return;
    }

    void insertAtHead(int id, string name, double price)
    {

        Node *nn = new Node(id, name, price);

        if (head == nullptr)
        {
            head = nn;
            tail = nn;
            return;
        }

        head->prev = nn;
        nn->next = head;
        head = nn;
        return;
    }

    void deleteAtFront()
    {
        if (head == nullptr)
        {
            cout << "List does not exist\n";
            return;
        }

        Node *temp = head;
        if (head == tail)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }

    void deleteAtEnd()
    {
        if (head == nullptr)
        {
            cout << "List does not exist\n";
            return;
        }

        Node *temp = tail;
        if (head == tail)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }

    void searchByID(int id)
    {
        Node *temp = head;
        if (head == nullptr)
        {
            cout << "List is empty";
            return;
        }
        while (temp != nullptr)
        {
            if (temp->id == id)
            {
                cout << "ID: " << temp->id << endl;
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

    void updateByID(int id, double newprice)
    {
        Node *temp = head;
        if (head == nullptr)
        {
            cout << "List is empty";
            return;
        }
        while (temp != nullptr)
        {
            if (temp->id == id)
            {
                temp->price = newprice;
                return;
            }
            temp = temp->next;
        }
        cout << "Item is not in the cart \n";
        return;
    }

    void diplayListFromFront()
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

    void diplayListFromEnd()
    {
        Node *temp = tail;
        if (head == nullptr)
        {
            cout << "List is empty";
            return;
        }
        while (temp != nullptr)
        {
            cout << "\nName:" << temp->name << endl;
            cout << "Price: $" << temp->price << endl;
            temp = temp->prev;
        }
        return;
    }
};

int main()
{
    Node *n1 = new Node(1, "Laptop", 1000);
    LinkedList l1(n1);
    l1.insertAtTail(2, "Phone", 700);
    l1.insertAtTail(3, "Tablet", 400);
    l1.insertAtTail(4, "Headphones", 150);
    l1.diplayListFromFront();

    l1.insertAtHead(5, "SmartWatch", 300);
    l1.insertAtTail(6, "Keyboard", 150);
    cout << "Added items at the head and tail\n";
    l1.diplayListFromFront();

    l1.searchByID(3);
    l1.updateByID(2, 800);
    l1.diplayListFromFront();

    l1.deleteAtEnd();
    l1.deleteAtFront();

    cout << "\nList from end\n";
    l1.diplayListFromEnd();
    cout << "\nList from front\n";
    l1.diplayListFromFront();

}