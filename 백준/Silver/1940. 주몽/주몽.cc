#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;

    cin >> N >> M;

    int A[N];

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    sort(A, A + N);

    int i = 0, j = N - 1, count = 0;
    while (i < j)
    {
        int sum = A[i] + A[j];

        if (sum == M)
        {
            count++;
            i++;
        }
        else if (sum < M)
        {
            i++;
        }
        else
        { // sum > M
            j--;
        }
    }

    cout << count << endl;
}