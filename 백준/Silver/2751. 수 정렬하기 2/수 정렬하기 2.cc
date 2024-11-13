#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &A, vector<int> &temp, int S, int M, int E);

void merge_sort(vector<int> &A);

void merge_sort_helper(vector<int> &A, vector<int> &temp, int S, int E)
{
    if (S < E)
    {
        int M = (S + E) / 2;

        merge_sort_helper(A, temp, S, M);
        merge_sort_helper(A, temp, M + 1, E);
        int i = S;
        int j = M + 1;
        int k = S;

        while (i <= M && j <= E)
        {
            if (A[i] <= A[j])
            {
                temp[k++] = A[i++];
            }
            else
            {
                temp[k++] = A[j++];
            }
        }

        if (i <= M)
        {
            for (int l = i; l <= M; l++)
            {
                temp[k++] = A[l];
            }
        }
        else
        {
            for (int l = j; l <= E; l++)
            {
                temp[k++] = A[l];
            }
        }

        for (int l = S; l <= E; l++)
        {
            A[l] = temp[l];
        }
    }
}

void merge(vector<int> &A, vector<int> &temp, int S, int M, int E)
{
    int i = S;
    int j = M + 1;
    int k = S;

    while (i <= M && j <= E)
    {
        if (A[i] <= A[j])
        {
            temp[k++] = A[i++];
        }
        else
        {
            temp[k++] = A[j++];
        }
    }

    if (i <= M)
    {
        for (int l = i; l <= M; l++)
        {
            temp[k++] = A[l];
        }
    }
    else
    {
        for (int l = j; l <= E; l++)
        {
            temp[k++] = A[l];
        }
    }

    for (int l = S; l <= E; l++)
    {
        A[l] = temp[l];
    }
}

void merge_sort(vector<int> &A)
{
    vector<int> temp(A.size(), 0);

    merge_sort_helper(A, temp, 0, A.size() - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> A(N, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    merge_sort(A);

    for (int i = 0; i < N; i++)
    {
        cout << A[i] << "\n";
    }
}