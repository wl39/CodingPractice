#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

long long count(long long N, long long T)
{
    long long c = 0;

    for (long long i = 1; i <= N; i++)
    {
        c += min(T / i, N);
    }

    return c;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N, K;

    cin >> N >> K;

    long long S = 1, E = N * N, M, R;

    while (S <= E)
    {
        M = (S + E) / 2;

        long long C = count(N, M);

        // cout << C << " " << M << endl;

        if (C < K)
        {
            S = M + 1;
        }
        else
        {
            R = M;
            E = M - 1;
        }
    }

    cout << R << endl;
}

//

// 9 2 1 2 3 4 5 6 7 8 9