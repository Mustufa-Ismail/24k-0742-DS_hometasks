#include <iostream>
#include <cmath>
using namespace std;

class stack
{
public:
    int Top;
    double *arr;
    int capacity;

    stack(int cap) : Top(-1), capacity(cap)
    {
        arr = new double[capacity];
    }

    void push(double x)
    {
        if (isFull())
        {
            cout << "Stack overflow";
            return;
        }
        Top++;
        arr[Top] = x;
    }

    double pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow";
            return -1;
        }
        return arr[Top--];
    }

    double top()
    {
        if (isEmpty())
        {
            cout << "Stack underflow";
            return -1;
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

double evaluatePostfix(string postfix)
{
    stack s(postfix.length());

    for (int i = 0; i < postfix.length(); i++)
    {
        char c = postfix[i];

        if (c >= '0' && c <= '9')
        {
            s.push(c - '0');
        }

        else
        {
            double operand2 = s.pop();
            double operand1 = s.pop();
            double result;

            switch (c)
            {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                if (operand2 == 0)
                {
                    cout << "Error: Division by zero" << endl;
                    return -1;
                }
                result = operand1 / operand2;
                break;
            case '^':
                result = pow(operand1, operand2);
                break;
            default:
                cout << "Error: Invalid operator " << endl;
                return -1;
            }
            s.push(result);
        }
    }

    return s.pop();
}

int main()
{

    cout << evaluatePostfix("23*54*+9-");

    return 0;
}
