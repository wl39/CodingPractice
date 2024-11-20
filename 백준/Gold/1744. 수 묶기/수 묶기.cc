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

    int N;

    cin >> N;

    priority_queue<int, vector<int>, less<int>> PPQ;
    priority_queue<int, vector<int>, greater<int>> NPQ;
    bool hasZero = false;

    int sum = 0;

    for (int i = 0; i < N; i++)
    {
        int V;
        cin >> V;

        if (V == 1)
        {
            sum++;
        }
        else if (V > 0)
        {
            PPQ.push(V);
        }
        else if (V < 0)
        {
            NPQ.push(V);
        }
        else
        {
            hasZero = true;
        }
    }

    while (!PPQ.empty())
    {
        int v1, v2;

        if (PPQ.size() > 1)
        {
            v1 = PPQ.top();
            PPQ.pop();

            v2 = PPQ.top();
            PPQ.pop();

            sum += v1 * v2;
        }
        else
        {
            v1 = PPQ.top();
            PPQ.pop();

            sum += v1;
        }
    }

    while (!NPQ.empty())
    {
        int v1, v2;

        if (NPQ.size() > 1)
        {
            v1 = NPQ.top();
            NPQ.pop();

            v2 = NPQ.top();
            NPQ.pop();

            sum += v1 * v2;
        }
        else
        {
            v1 = NPQ.top();
            NPQ.pop();

            if (!hasZero)
                sum += v1;
        }
    }

    cout << sum << "\n";
}
