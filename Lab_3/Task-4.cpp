#include <iostream>
using namespace std;

class Node
{
public:
    int id;
    string customerName;
    string rideName;
    Node *next;

    Node() : id(0), customerName(""), rideName(""), next(nullptr) {};
    Node(int id, string customerName, string rideName) : id(id), customerName(customerName), rideName(rideName), next(nullptr) {};
};

class CircularLinkedList
{
public:
    Node *head;
    Node *tail;

    CircularLinkedList(Node *head) : head(head)
    {
        head->next = head;
        tail = head;
    }

    void insertAtEnd(int id, string customerName, string rideName)
    {
        Node *nn = new Node(id, customerName, rideName);
        if (head == nullptr)
        {
            head = nn;
            head->next = nn;
            tail = head;
            return;
        }

        tail->next = nn;
        nn->next = head;
        tail = nn;
    }

    void insertAtStart(int id, string customerName, string rideName)
    {
        Node *nn = new Node(id, customerName, rideName);
        if (head == nullptr)
        {
            head = nn;
            head->next = nn;
            tail = head;
            return;
        }

        nn->next = head;
        tail->next = nn;
        head = nn;
    }

    void displayList()
    {
        cout << "List:" << endl;
        Node *temp = head;
        do
        {
            cout << "\nID: " << temp->id << endl;
            cout << "Customer Name: " << temp->customerName << endl;
            cout << "Ride Name: " << temp->rideName << endl;
            temp = temp->next;
        } while (temp != head);
        cout << "\nID: " << head->id << endl;
        cout << "Customer Name: " << head->customerName << endl;
        cout << "Ride Name: " << head->rideName << endl;
    }

    void deleteAtStart()
    {
        if (head == nullptr)
        {
            cout << "list is empty";
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
            tail->next = temp->next;
            head = tail->next;
        }
        delete temp;
        return;
    }

    void deleteById(int id)
    {
        if (head == nullptr)
        {
            cout << "list is empty";
            return;
        }

        if (head->id == id)
        {
            deleteAtStart();
            return;
        }

        Node *temp = head;
        do
        {
            if (temp->next->id == id)
            {
                Node *temp2 = temp->next;
                temp->next = temp2->next;

                if (temp2 == tail)
                {
                    tail = temp;
                }

                delete temp2;
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "ticket ID not found" << endl;
    }

    Node *searchByID(int id)
    {
        if (head == nullptr)
        {
            cout << "List does not exist";
            return nullptr;
        }
        Node *temp = head;
        do
        {
            if (temp->id == id)
            {
                return temp;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Id not found";
        return nullptr;
    }

    void findNextByID(int id)
    {
        Node *currentNode = searchByID(id);
        if (currentNode == nullptr)
        {
            return;
        }
        Node *nextNode = currentNode->next;
        cout << "\nNext ticket in list is \n";
        cout << "\nID: " << nextNode->id << endl;
        cout << "Customer Name: " << nextNode->customerName << endl;
        cout << "Ride Name: " << nextNode->rideName << endl;
    }

    void countTickets()
    {
        if (head == nullptr)
        {
            cout << "Total number of tickets are: 0" << endl;
            return;
        }
        int count = 0;
        Node *temp = head;
        do
        {
            count++;
            temp = temp->next;
        } while (temp != head);
        cout << "Total number of tickets are: " << count << endl;
    }
};

int main()
{
    Node *n1 = new Node(1, "A", "xyz");
    CircularLinkedList l1(n1);

    l1.insertAtStart(2, "B", "xyz");
    l1.insertAtEnd(3, "c", "xyz");
    l1.insertAtEnd(4, "d", "xyz");
    l1.insertAtEnd(5, "e", "xyz");
    l1.countTickets();

    l1.displayList();

    l1.deleteAtStart();
    l1.deleteById(3);

    l1.displayList();

    cout << "\nSearching " << endl;
    Node *n2 = l1.searchByID(1);
    cout << "\nID: " << n2->id << endl;
    cout << "Customer Name: " << n2->customerName << endl;
    cout << "Ride Name: " << n2->rideName << endl;

    l1.findNextByID(1);
}
