#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, v, sv = 1, c = 0;

    stack<int> s;
    queue<char> q;

    bool b = false;

    cin >> n;

    while (c != n)
    {
        cin >> v;

        while (sv <= v)
        {
            s.push(sv++);
            q.push('+');
            b = true;
        }

        if (s.size() != 0 && s.top() == v)
        {
            c++;
            s.pop();
            q.push('-');
            b = true;
        }

        if (!b)
        {
            cout << "NO\n";
            return 0;
        }

        b = false;
    }

    while (q.size())
    {
        cout << q.front() << '\n';
        q.pop();
    }
}
