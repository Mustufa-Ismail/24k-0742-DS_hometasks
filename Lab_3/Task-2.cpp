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
    Node *tail;

    LinkedList() : head(nullptr), tail(nullptr) {};
    LinkedList(Node *next) : head(next), tail(next) {};

    void insertAtTail(string name, double price)
    {

        Node *nn = new Node(name, price);

        if (head == nullptr)
        {
            head = nn;
            tail = nn;
            return;
        }
        else if (head->next == nullptr)
        {
            head->next = nn;
            tail = nn;
            return;
        }

        tail->next = nn;
        tail = nn;
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
        head = head->next;
        delete temp;
    }

    void searchByValue(string val)
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

    void searchByPosition(int pos)
    {
        Node *temp = head;
        if (head == nullptr)
        {
            cout << "List is empty";
            return;
        }
        int count = 1;
        while (temp != nullptr)
        {
            if (count == pos)
            {
                cout << "\nitem exists in the cart at positon " << count << endl;
                cout << "Name:" << temp->name << endl;
                cout << "Price: $" << temp->price << endl
                     << endl;
                return;
            }
            count++;
            temp = temp->next;
        }
        cout << "Positon does not exist \n";
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
    l1.insertAtTail("Phone", 700);
    l1.insertAtTail("Tablet", 400);
    l1.insertAtTail("Headphones", 150);
    l1.diplayList();

    l1.deleteAtFront();
    cout << "\nAfter deleteing \n";
    l1.diplayList();
    l1.searchByPosition(2);
    l1.searchByValue("Headphones");
}