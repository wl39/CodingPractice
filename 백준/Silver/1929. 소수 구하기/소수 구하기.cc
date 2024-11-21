#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, N;

    cin >> M >> N;

    vector<bool> A(N + 1, true);

    A[1] = false;

    for (int i = 2; i <= sqrt(N); i++)
    {
        if (!A[i])
            continue;
        for (int j = 2; j <= N / i; j++)
        {
            A[i * j] = false;
        }
    }

    A[2] = true;

    for (int i = M; i <= N; i++)
    {
        if (A[i])
        {
            cout << i << "\n";
        }
    }
}
