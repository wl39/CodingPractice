#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> node;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;

    cin >> N;

    vector<vector<node>> T(N, vector<node>());
    vector<bool> visited(N, false);
    vector<int> D(N, 0);

    for (int i = 0; i < N; i++)
    {
        int P, V = 0, E = 0;

        cin >> P;

        while (true)
        {
            cin >> V;

            if (V < 0)
                break;

            cin >> E;

            T[P - 1].push_back(node(V - 1, E));
        }
    }

    // BFS

    queue<int> Q;

    // for (int i = 0; i < N; i++)
    // {
    //     cout << i + 1 << " -> ";
    //     for (int j = 0; j < T[i].size(); j++)
    //     {
    //         cout << T[i][j].first + 1 << " ";
    //     }
    //     cout << endl;
    // }

    int maximum = 0;
    int next = 0;
    int start = 0;
    for (int i = 0; i < 2; i++)
    {
        Q.push(start);
        while (!Q.empty())
        {
            int P = Q.front();
            Q.pop();

            if (visited[P])
            {
                continue;
            }

            visited[P] = true;

            for (node VE : T[P])
            {
                if (!visited[VE.first])
                {
                    D[VE.first] = D[P] + VE.second;

                    if (D[VE.first] > maximum)
                    {
                        maximum = max(maximum, D[VE.first]);
                        start = VE.first;
                    }
                }

                Q.push(VE.first);
            }
        }

        // for (int i = 0; i < N; i++)
        // {
        //     cout << D[i] << " ";
        // }

        // cout << "| " << maximum << " : " << start;
        // cout << endl;

        D = vector(N, 0);
        visited = vector(N, false);
    }

    cout << maximum << "\n";

    // sort(D.begin(), D.end());
}