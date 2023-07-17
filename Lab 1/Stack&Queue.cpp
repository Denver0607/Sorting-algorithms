#include <iostream>
#include <string>

using namespace std;

struct Node
{
    int key;
    Node *pNext;
};

struct Stack
{
    Node *pTop;
};

int checkEmpty(Stack s)
{
    return (s.pTop == NULL);
}

Stack initialize(int key)
{
    Stack s;
    s.pTop->key = key;
    s.pTop->pNext = NULL;
    return s;
}

void Push(Stack &s, int key)
{
    Node *temp = new Node();
    temp->key = key;
    temp->pNext = NULL;
    if (s.pTop == NULL)
    {
        s.pTop = temp;
    }
    else
    {
        temp->pNext = s.pTop;
        s.pTop = temp;
    }
}

int Pop(Stack &s)
{
    if (s.pTop == NULL)
        return -1;
    Node *temp = s.pTop;
    int key = temp->key;
    s.pTop = s.pTop->pNext;
    delete temp;
    return key;
}

void showStack(Stack s)
{
    for (Node *p = s.pTop; p; p = p->pNext)
    {
        cout << p->key << " ";
    }
    cout << endl;
}

int main()
{
    Stack s;
    s.pTop = NULL;
    int key;
    while (1)
    {
        cout << "key = ";
        cin >> key;
        if (key != -1)
            Push(s, key);
        else
            break;
    }
    showStack(s);
    int result=Pop(s);
    cout << "Pop(s) = " << result << endl;
    showStack(s);
    return 0;
}