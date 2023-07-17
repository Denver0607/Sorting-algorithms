#include <iostream>

using namespace std;

struct NODE
{
    int key;
    NODE *p_next;
};

struct List
{
    NODE *p_head;
    NODE *p_tail;
};

// Initialize a NODE from a given integer:
NODE *createNode(int data)
{
    NODE *temp = new NODE();
    temp->key = data;
    temp->p_next = NULL;
    return temp;
}

// Initialize a List from a give NODE:
List createList(NODE *p_node)
{
    List l;
    l.p_head = l.p_tail = p_node;
    return l;
}

// Insert an integer to the head of a given List:
bool addHead(List &l, int data)
{
    NODE *temp = createNode(data);
    if (l.p_head == NULL)
    {
        l.p_head = l.p_tail = temp;
        return 1;
    }
    else
    {
        temp->p_next = l.p_head;
        l.p_head = temp;
        return 1;
    }
}

int main()
{
    int option, x, n, a, b, data;
    List l;
    l.p_head = l.p_tail = NULL;
    while (1)
    {
        // Define a menu
        cout << "--------------------MENU----------------------\n";
        cout << "1. Show list\n";
        cout << "2. Add head\n";
        cout << "3. Reverse linked list\n";
        cout << "4. Count the number of digits of a given integer\n";
        cout << "5. Verify if every digits of given integer are even\n";
        cout << "6. Count the number of common divisor of 2 given integers\n";
        cout << "0. Stop\n";
        cout << "--------------------------\n";
        cout << "Your choice = ";
        cin >> option;
        if (option == 1)
        {
            for (NODE *p = l.p_head; p; p = p->p_next)
            {
                cout << p->key << " ";
            }
            cout << endl;
        }
        else if (option == 2)
        {
            cout << "data = ";
            cin >> data;
            addHead(l, data);
        }
        else if (option == 3)
        {
            List result;
            result.p_head = result.p_tail = NULL;
            for (NODE *p = l.p_head; p; p = p->p_next)
            {
                addHead(result, p->key);
            }
            for (NODE *p = result.p_head; p; p = p->p_next)
            {
                cout << p->key << " ";
            }
            cout << endl;
        }
        // else if (option == 4)
        // {
        //     cout << "n = ";
        //     cin >> n;
        //     cout << "Number of digits of " << n << " = " << numberOfDigits(n) << endl;
        // }
        // else if (option == 5)
        // {
        //     cout << "n = ";
        //     cin >> n;
        //     if (verifyEvenDigit(n) == 1)
        //         cout << "Every digits of " << n << " are even\n";
        //     else cout << "Every digits of " << n << " are not even\n";
        // }
        // else if (option == 6)
        // {
        //     cout << "a = ";
        //     cin >> a;
        //     cout << "b = ";
        //     cin >> b;
        //     cout << "There are " << countCommonDivisor(a,b) << "number of common divisor of " << a << " and " << b << endl;
        // }
        else if (option == 0)
            break;
    }
}
