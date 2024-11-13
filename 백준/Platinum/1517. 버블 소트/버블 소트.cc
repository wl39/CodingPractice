#include <iostream>
#include <vector>

using namespace std;

void merge_sort(vector<int> &A, int &result);

void merge_sort_helper(vector<int> &A, vector<int> &temp, int S, int E, long &result)
{
    if (S < E)
    {
        int M = (S + E) / 2;

        merge_sort_helper(A, temp, S, M, result);
        merge_sort_helper(A, temp, M + 1, E, result);
        int i = S;
        int j = M + 1;
        int k = S;

        while (i <= M && j <= E)
        {
            if (A[i] <= A[j])
            {
                if (i - k > 0)
                    result += i - k;

                temp[k++] = A[i++];
            }
            else
            {
                if (j - k > 0)
                    result += j - k;

                temp[k++] = A[j++];
            }
        }

        if (i <= M)
        {
            for (int l = i; l <= M; l++)
            {
                if (l - k > 0)
                    result += l - k;

                temp[k++] = A[l];
            }
        }
        else
        {
            for (int l = j; l <= E; l++)
            {
                if (l - k > 0)
                    result += l - k;

                temp[k++] = A[l];
            }
        }

        for (int l = S; l <= E; l++)
        {
            A[l] = temp[l];
        }
    }
}

void merge_sort(vector<int> &A, long &result)
{
    vector<int> temp(A.size(), 0);

    merge_sort_helper(A, temp, 0, A.size() - 1, result);
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

    long result = 0;
    merge_sort(A, result);

    // for (int i = 0; i < N; i++)
    // {
    //     cout << A[i] << "\n";
    // }

    cout << result << "\n";
}