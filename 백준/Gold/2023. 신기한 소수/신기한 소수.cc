#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int n)
{
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}
void DFS(int n, int p, int N)
{
    if (p == N)
    {
        if (isPrime(n))
            cout << n << "\n";

        return;
    }

    for (int i = 1; i <= 9; i += 2)
    {
        if (isPrime(n))
        {
            DFS(n * 10 + i, p + 1, N);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;

    cin >> N;

    // 2 3 5 7
    // 1 3 5 7 9

    DFS(2, 1, N);
    DFS(3, 1, N);
    DFS(5, 1, N);
    DFS(7, 1, N);
}