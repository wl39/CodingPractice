#include <iostream>

using namespace std;

// struct;
/**
 * 5 3
    5 4 3 2 1
    1 3
    2 4
    5 5
 */
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;

    cin >> N >> M;

    int A[N];
    int S[N + 1];

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];

        S[i + 1] = S[i] + A[i];
    }

    int i, j;

    // 0 1 2 3 4
    // 1 2 3 4 5
    // 5 4 3 2 1
    // 1 3 6

    for (int m = 0; m < M; m++)
    {
        cin >> i >> j;

        cout << S[j] - S[i - 1] << '\n';
    }
}
