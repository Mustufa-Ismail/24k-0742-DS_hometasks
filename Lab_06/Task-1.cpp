#include <iostream>
using namespace std;

struct calldetail
{
    string name;
    int number;
    int duration;

    calldetail(string n = "", int num = 0, int dur = 0) : name(n), number(num), duration(dur) {}
};

class stack
{
public:
    int Top;
    calldetail arr[100];

    stack() : Top(-1) {}

    void push(calldetail x)
    {
        if (isFull())
        {
            cout << "Stack overflow";
            return;
        }
        Top++;
        arr[Top] = x;
    }

    calldetail pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow";
            return calldetail();
        }
        return arr[Top--];
    }

    calldetail top()
    {
        if (isEmpty())
        {
            cout << "Stack underflow";
            return calldetail();
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

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return;
        }

        cout << "Call History (most recent first)" << endl;

        for (int i = Top; i >= 0; i--)
        {
            cout << "Name: " << arr[i].name;
            cout << " Number: " << arr[i].number;
            cout << " Call Duration: " << arr[i].duration;
            cout << endl;
        }
    }
};

int main()
{
    stack callStack;

    calldetail c1("A", 12345, 10);
    calldetail c2("B", 67890, 5);
    calldetail c3("C", 54321, 15);

    callStack.push(c1);
    callStack.push(c2);
    callStack.push(c3);
    callStack.display();

    cout << "After pushing calls: " << endl;
    callStack.display();

    cout << "\n Top call:";
    calldetail topCall = callStack.top();
    cout << topCall.name << " - " << topCall.number << endl;

    cout << "\n Popping top call" << endl;
    callStack.pop();
    callStack.display();

    cout << "Final stack:" << endl;
    callStack.display();

    return 0;
}