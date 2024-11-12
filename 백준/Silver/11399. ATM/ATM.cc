#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> node;

int main()
{
    // how many times the value move from right to left;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;

    cin >> N;

    int A[N];
    vector<int> S(N, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    S[0] = A[0];

    for (int i = 1; i < N; i++)
    {
        int insertIndex = i;
        for (int j = i - 1; j >= 0; j--)
        {
            if (A[i] < S[j])
            {
                insertIndex = j;
            }
        }


        for (int j = i; j > insertIndex; j--)
        {
            S[j] = S[j - 1];
        }

        S[insertIndex] = A[i];

    }

    int result = 0;

    for (int i = 0; i < N; i++)
    {
        result += S[i] * (N - i);
    }

    cout << result << endl;
}