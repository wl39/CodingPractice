#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> node;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;

    cin >> N;

    vector<int> A(N, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int v;
        cin >> v;

        int S = 0, E = A.size() - 1, M = (S + E) / 2;
        bool find = false;
        while (S <= E)
        {
            M = (S + E) / 2;

            if (v < A[M])
            {
                E = M - 1;
            }
            else if (v > A[M])
            {
                S = M + 1;
            }
            else
            {
                cout << "1\n";
                find = true;
                break;
            }
        }

        if (!find)
            cout << "0\n";
        // return 0;
    }
}