#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, count = 0, end;

    cin >> N;

    vector<pair<int, int>> A(N, pair<int, int>(0, 0));

    for (int i = 0; i < N; i++)
    {
        cin >> A[i].second;
        cin >> A[i].first;
    }

    sort(A.begin(), A.end());

    end = A[0].first;
    count++;

    for (int i = 1; i < N; i++)
    {
        if (A[i].second >= end)
        {
            end = A[i].first;
            count++;
        }
    }

    cout << count << "\n";
}
