#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> node;
int K;
int partition(vector<int> &A, int S, int E);
void q_sort(vector<int> &A, int S, int E);

void q_sort(vector<int> &A, int S, int E)
{
    if (S < E)
    {
        int pivot = partition(A, S, E);

        if (K == pivot)
        {
            return;
        }
        else if (K < pivot)
        {
            q_sort(A, S, pivot - 1);
        }
        else
        {
            q_sort(A, pivot + 1, E);
        }
    }
}

int partition(vector<int> &A, int S, int E)
{
    int M = (S + E) / 2;
    swap(A[E], A[M]);
    int pivot = A[E];
    int start = S;
    int end = E - 1;

    while (start <= end)
    {
        while (end >= S && A[end] > pivot)
        {
            end--;
        }

        while (start <= E - 1 && A[start] < pivot)
        {
            start++;
        }

        if (start < end)
        {
            swap(A[start++], A[end--]);
        }
        else
        {
            break;
        }
    }

    // cout << start << " " << end << "|" << S << " " << E << endl;

    A[E] = A[end + 1];
    A[end + 1] = pivot;
    // A[end + 1] = A[]

    // for (int i = 0; i < A.size(); i++)
    // {
    //     cout << A[i];
    // }

    // cout << endl;

    return end + 1;
}

int main()
{
    // how many times the value move from right to left;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // 2 1 3 4 5
    // 2 1 4 5 3
    int N;

    cin >> N >> K;
    K--;

    // int A[N];
    vector<int> S(N, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> S[i];
    }

    q_sort(S, 0, N - 1);

    // for (int i = 0; i < N; i++)
    // {
    //     cout << S[i];
    // }

    // cout << endl;

    cout << S[K] << endl;
}
