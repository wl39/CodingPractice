#include <iostream>
#include <vector>
#include <deque>

using namespace std;
// index, value
typedef pair<int, int> node;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    deque<node> deq;

    int n, l, v;

    cin >> n >> l >> v;

    deq.push_back(node(0, v));

    cout << v << ' ';

    for (int i = 1; i < n; i++)
    {
        cin >> v;

        if (deq.front().first <= i - l)
        {
            deq.pop_front();
        }

        while (deq.size() && deq.back().second >= v)
        {
            deq.pop_back();
        }

        // if (deq.back().second >= v)
        // {
        // }

        deq.push_back(node(i, v));

        cout << deq.front().second << ' ';
    }

    cout << '\n';
}
