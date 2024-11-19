#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int N;

    cin >> N;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < N; i++)
    {
        int V;
        cin >> V;

        pq.push(V);
    }

    int sum = 0;

    while (!pq.empty())
    {
        int local;

        if (pq.size() > 1)
        {
            local = pq.top();
            pq.pop();
            local += pq.top();
            pq.pop();

            pq.push(local);

            sum += local;
        }
        else
        {
            pq.pop();
        }
    }

    cout << sum;
}