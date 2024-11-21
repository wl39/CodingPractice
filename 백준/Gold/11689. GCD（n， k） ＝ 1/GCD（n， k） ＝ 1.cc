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

    long long N;

    cin >> N;

    long long K = sqrt(N);

    long long result = N;

    for (long long i = 2; i <= K; i++)
    {
        if (N % i == 0)
        {
            result -= result / i;

            while (N % i == 0)
            {
                N /= i;
            }
        }
    }

    if (N > 1)
    {
        result -= result / N;
    }
    // cout << "\n";
    /// 99 -> 66

    cout << result << "\n";
}
