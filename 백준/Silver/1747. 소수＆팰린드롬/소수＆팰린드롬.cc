#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <string>

using namespace std;

bool palindrome(string s)
{
    for (int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--)
    {
        if (s[i] != s[j])
            return false;
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;

    cin >> N;

    vector<bool> A(10000001, true);

    for (int i = 2; i <= sqrt(10000000); i++)
    {
        if (!A[i])
            continue;

        for (int j = 2; j <= 10000000 / i; j++)
        {
            A[i * j] = false;
        }
    }

    A[0] = false;
    A[1] = false;

    for (int i = N; i < 10000001; i++)
    {
        if (A[i])
        {
            string s = to_string(i);

            if (palindrome(s))
            {
                cout << i << endl;
                break;
            }
        }
    }
}
