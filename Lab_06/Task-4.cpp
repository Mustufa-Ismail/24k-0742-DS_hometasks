#include <iostream>
using namespace std;

class stack
{
public:
    int Top;
    char *arr;
    int capacity;

    stack(int cap) : Top(-1), capacity(cap)
    {
        arr = new char[capacity];
    }

    void push(char x)
    {
        if (isFull())
        {
            cout << "Stack overflow";
            return;
        }
        Top++;
        arr[Top] = x;
    }

    char pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow";
            return '\0';
        }
        return arr[Top--];
    }

    char top()
    {
        if (isEmpty())
        {
            cout << "Stack underflow";
            return '\0';
        }
        return arr[Top];
    }

    bool isEmpty()
    {
        return (Top < 0);
    }

    bool isFull()
    {
        return (Top >= capacity - 1);
    }
};

int precedence(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string InfixToPostfix(string infix)
{
    string postfix = "";
    int length = infix.length();
    stack s(length);

    for (int i = 0; i < length; i++)
    {
        char c = infix[i];
        
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            postfix += c;
        }

        else if (c == '(')
        {
            s.push(c);
        }

        else if (c == ')')
        {
            while (!s.isEmpty() && s.top() != '(')
            {
                char op = s.pop();
                postfix += op;
            }
            if (!s.isEmpty() && s.top() == '(')
            {
                s.pop();
            }
        }

        else
        {
            while (!s.isEmpty() && precedence(c) <= precedence(s.top()))
            {
                char op = s.pop();
                postfix += op;
            }
            s.push(c);
        }
    }

    while (!s.isEmpty())
    {
        char op = s.pop();
        postfix += op;
    }
    
    return postfix;
}

int main(){
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << InfixToPostfix(infix) << endl;

    return 0;
}