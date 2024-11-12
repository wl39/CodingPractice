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

    string N;

    cin >> N;

    int A[N.length()];

    for (int i = 0; i < N.length(); i++)
    {
        A[i] = N[i] - '0';
    }

    for (int i = 0; i < N.length(); i++)
    {
        int MAX = A[i];
        int index = i;

        for (int j = i + 1; j < N.length(); j++)
        {
            if (A[j] > MAX)
            {
                index = j;
                MAX = A[j];
            }
        }

        int temp = A[i];
        A[i] = MAX;
        A[index] = temp;

        cout << A[i];
    }

    cout << endl;
}