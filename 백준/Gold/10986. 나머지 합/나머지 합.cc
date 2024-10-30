#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long n, m;

    cin >> n >> m;

    vector<long> sum(n + 1, 0);
    vector<long> modu(m, 0);
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;

        sum[i] = sum[i - 1] + temp;
    }

    for (int i = 1; i <= n; i++)
    {
        modu[sum[i] % m]++;
    }

    long long result = modu[0];

    for (int i = 0; i < m; i++)
    {
        if (modu[i] > 0)
            result += modu[i] * (modu[i] - 1) / 2;
    }

    cout << result << '\n';
}