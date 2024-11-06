#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;
    queue<int> q;

    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }

    while (q.size() != 1)
    {
        // drop the card
        q.pop();

        int f = q.front();

        q.pop();
        q.push(f);
    }

    cout << q.front() << '\n';
}
