#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N, M;

    cin >> N >> M;

    vector<bool> A(M - N + 1, false);

    for (long long i = 2; i <= sqrt(M); i++)
    {
        long long V = i * i;
        long long C = V * (N / V);
        long long index = C - N;

        // if (index >= 0 && A[index])
        // {
        //     cout << V << endl;
        //     continue;
        // }

        while (C <= M)
        {
            index = C - N;

            if (index >= 0)
                A[index] = true;

            C += V;
        }
    }

    long long count = 0;

    for (long long i = 0; i < A.size(); i++)
    {
        if (!A[i])
            count++;
    }

    cout << count << endl;
}
