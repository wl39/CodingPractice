#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 0, m = 0;

    cin >> n >> m;

    int s[1000001];

    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        s[i] = s[i - 1] + temp;
    }

    for (int i = 0; i < m; i++)
    {
        int from = 0, to = 0;

        cin >> from >> to;

        cout << s[to] - s[from - 1] << '\n';
    }
}