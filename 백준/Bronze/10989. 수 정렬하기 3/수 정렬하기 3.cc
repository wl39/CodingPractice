#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;

    cin >> N;

    vector<int> count(10001, 0);

    for (int i = 0; i < N; i++)
    {
        int index = 0;

        cin >> index;

        count[index]++;
    }

    for (int i = 1; i < 10001; i++)
    {
        for (int j = 0; j < count[i]; j++)
        {
            cout << i << "\n";
        }
    }
}