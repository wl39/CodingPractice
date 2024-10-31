#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;

    vector<int> A(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    int target = A[0], count = 0;

    for (int index = 0; index < n; index++)
    {
        int i = 0, j = n - 1;

        target = A[index];

        while (i < j)
        {
            if (A[i] + A[j] == target)
            {
                if (i != index && j != index)
                {
                    count++;
                    break;
                }
                else if (i == index)
                {
                    i++;
                }
                else if (j == index)
                {
                    j--;
                }
            }
            else if (A[i] + A[j] > target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
    }

    cout << count << '\n';
}