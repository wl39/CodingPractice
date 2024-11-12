#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> node;

int main()
{
    // how many times the value move from right to left;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, V;

    cin >> N;

    vector<node> array;

    for (int i = 0; i < N; i++)
    {
        cin >> V;

        node v(V, i);

        array.push_back(v);
    }

    sort(array.begin(), array.end());

    int maxValue = -1;

    for (int i = 0; i < N; i++)
    {
        maxValue = max(maxValue, array[i].second - i);
    }

    cout << maxValue + 1 << endl;
}