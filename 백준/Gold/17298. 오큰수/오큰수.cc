#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, v;
    cin >> n;

    vector<int> a(n, 0);
    vector<int> ans(n, -1);
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    s.push(0);

    for (int i = 1; i < n; i++)
    {
        if (a[s.top()] > a[i])
        {
            s.push(i);
        }
        else
        {
            while (s.size() && a[s.top()] < a[i])
            {
                ans[s.top()] = a[i];
                s.pop();
            }

            s.push(i);
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << ' ';
    }

    cout << '\n';
}
