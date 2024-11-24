#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long N, start = 1, sum = 0;

    cin >> N;

    while (sum < N)
    {
        sum += start++;
    }

    if (sum == N)
    {
        cout << start - 1 << endl;
    }
    else
    {
        cout << start - 2 << endl;
    }
}