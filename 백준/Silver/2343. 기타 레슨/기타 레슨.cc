#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> node;

int group(vector<int> &A, int v)
{
    int count = 1;
    int sum = 0;
    for (int i = A.size() - 1; i >= 0; i--)
    {
        sum += A[i];
        // cout << A[i] << "(" << count << ", " << sum << ") ";

        if (sum == v)
        {
            sum = 0;
            count++;
            continue;
        }
        else if (sum > v)
        {
            sum = 0;
            count++;
            i++;
            continue;
        }
    }

    // cout << endl;

    return count;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, sum = 0, S = 0;

    cin >> N >> M;

    vector<int> A(N, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        S = max(S, A[i]);
        sum += A[i];
    }

    int E = sum, v;

    while (S <= E)
    {
        v = (S + E) / 2;

        int C = 0;

        sum = 0;
        for (int i = A.size() - 1; i >= 0; i--)
        {
            // sum += A[i];
            if (sum + A[i] > v)
            {
                C++;
                sum = 0;
            }

            sum += A[i];
        }

        if (sum != 0)
        {
            C++;
        }

        // cout << C << " | " << v << "\n";
        if (C > M)
        {
            S = v + 1;
        }
        else
        {
            E = v - 1;
        }
        // else
        // {
        //     cout << s << endl;
        //     break;
        // }
    }

    cout << S << endl;

    // int min = v;

    // while (true)
    // {
    //     // int c = group(A, v - 1);

    //     int c = 1;

    //     sum = 0;
    //     for (int i = A.size() - 1; i >= 0; i--)
    //     {
    //         sum += A[i];
    //         // cout << A[i] << "(" << c << ", " << sum << ") ";

    //         if (sum == v - 1)
    //         {
    //             sum = 0;
    //             c++;
    //             continue;
    //         }
    //         else if (sum > v - 1)
    //         {
    //             sum = 0;
    //             c++;
    //             i++;
    //             continue;
    //         }
    //     }

    //     // cout << "\n";

    //     if (c > M)
    //     {
    //         cout << min << "\n";
    //         break;
    //     }

    //     if (c == M)
    //     {
    //         v--;
    //         min = v;
    //     }
    // }
}

//

// 9 2 1 2 3 4 5 6 7 8 9