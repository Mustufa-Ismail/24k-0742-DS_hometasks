#include <iostream>
using namespace std;

class queue
{
public:
    static const int maxSize = 10;
    string arr[maxSize];
    int front;
    int rear;

    int currentSize;

    queue() : front(-1), rear(-1), currentSize(0) {}

    bool isFull()
    {
        if (rear == maxSize - 1)
        {
            return true;
        }
        return false;
    }

    bool isEmpty()
    {
        if (rear == -1 && front == -1)
        {
            return true;
        }
        return false;
    }

    void enqueue(string n)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }
        else if (front == -1)
        {
            front = 0;
        }
        arr[++rear] = n;
        currentSize++;
    }

    string dequeue()
    {
        if (front > rear)
        {
            front = rear = -1;
        }
        int x = 0;
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return "";
        }

        string result = arr[front++];
        currentSize--;
        return result;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " -> ";
        }
        cout << endl;
    }
};

int main()
{
    queue library;

    library.enqueue("A");
    library.enqueue("B");
    library.enqueue("C");

    library.display();

    cout << "dequeued:" << library.dequeue() << endl;

    library.display();

    return 0;
}