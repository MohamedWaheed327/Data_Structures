// Mohamed_Waheed_
#include <bits/stdc++.h>
#define ll long long
using namespace std;

template <class T>
class Stack
{
private:
    struct node
    {
        T val;
        node *address = nullptr;
    };
    node *Top = nullptr;
    int Size = 0;

public:

    Stack() : Top(nullptr) {}

    ~Stack()
    {
        while (Top)
        {
            node *temp = Top;
            Top = Top->address;
            delete temp;
        }
    }

    void push(int x)
    {
        node *newnode = new node;
        newnode->val = x;
        newnode->address = Top;
        Top = newnode;
        Size++;
    }

    void pop()
    {
        node *temp = Top;
        Top = Top->address;
        delete temp;
        Size--;
    }

    T top()
    {
        return Top->val;
    }

    int size()
    {
        return Size;
    }

    bool empty()
    {
        return !Size;
    }
};

void Main()
{
    Stack<int> s;
    s.push(100);
    s.push(1);
    s.pop();
    s.push(1000);
    cout << s.top();
}
/*













*/
signed main()
{
    ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll T = 1;
    // cin >> T;
    for (ll i = 1; i <= T; i++)
    {
        Main();
        cout << '\n';
    }
    return 0;
}
