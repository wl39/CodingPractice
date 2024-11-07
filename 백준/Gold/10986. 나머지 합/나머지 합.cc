#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long N, M;

    cin >> N >> M;

    vector<long> S(N + 1, 0);
    vector<long> MOD(M, 0);

    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;

        S[i + 1] = S[i] + a;
        MOD[S[i + 1] % M]++;
    }

    long long result = 0;

    for (int i = 0; i < M; i++)
    {
        result += MOD[i] * (MOD[i] - 1) / 2;
    }

    cout << (result + MOD[0]) << endl;
}
