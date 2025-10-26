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
        return (Top >= capacity - 1);
    }
};
double evaluatePrefix(string prefix)
{
    stack s(prefix.length());

    for (int i = prefix.length() - 1; i >= 0; i--)
    {
        char c = prefix[i];

        if (c == ' ')
        {
            continue;
        }

        if (c >= '0' && c <= '9')
        {
            double num = 0;
            double multiplier = 1;
            int j = i;
            while (j >= 0 && prefix[j] >= '0' && prefix[j] <= '9')
            {
                num = (prefix[j] - '0') * multiplier + num;
                multiplier *= 10;
                j--;
            }
            i = j + 1;
            s.push(num);
        }
        else
        {
            double operand1 = s.pop();
            double operand2 = s.pop();
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
                cout << "Error: Invalid operator '" << c << "'" << endl;
                return -1;
            }
            s.push(result);
        }
    }

    return s.pop();
}

int main()
{

    cout << evaluatePrefix("+ * / + 100 200 2 5 7");

    return 0;
}
