#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, K;

    cin >> N >> K;

    vector<int> A(N, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    int coins = 0;

    for (int i = N - 1; i >= 0; i--)
    {
        int temp = 0;

        if (A[i] <= K)
        {
            temp = K / A[i];
            coins += K / A[i];
            K -= temp * A[i];
        }
    }

    cout << coins << endl;
}