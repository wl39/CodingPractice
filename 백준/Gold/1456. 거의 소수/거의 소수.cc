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

    long long M, N;

    cin >> M >> N;

    vector<bool> A(10000001, true);

    A[1] = false;

    for (long long i = 2; i <= sqrt(N); i++)
    {
        if (!A[i])
            continue;

        long long bound = min(N / i, 10000001 / i);

        for (long long j = 2; j <= bound; j++)
        {
            A[i * j] = false;
        }
    }

    A[2] = true;

    long long count = 0;

    for (long long i = 2; i <= 10000000; i++)
    {
        if (A[i])
        {
            long long V = i;

            // bool is = false;
            // cout << i << " = ";

            while ((double)V <= (double)N / i)
            {
                if ((double)V >= (double)M / i)
                    count++;

                // if (V >= M)
                //     cout << V << " ";
                // cout << V << " " << i << "\n";
                V *= i;

                // if (V < 0)
                // {
                // }
                // is = true;
            }

            // if (is)
            //     cout << " - " << count << "\n";
        }
    }

    // long k = 10000000;

    // long long a = k * k * 100;
    // cout << a << "\n";
    cout << count << "\n";
}
