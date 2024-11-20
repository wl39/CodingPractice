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

    string S;

    cin >> S;

    int sum = 0, n_sum = 0;
    ;

    vector<int> minus_position;
    vector<int> values;
    int start_index = 0;

    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] == '-')
        {
            values.push_back(stoi(S.substr(start_index, i - start_index)));

            start_index = i + 1;
            minus_position.push_back(values.size());
        }
        else if (S[i] == '+')
        {
            values.push_back(stoi(S.substr(start_index, i - start_index)));

            start_index = i + 1;
        }
    }

    values.push_back(stoi(S.substr(start_index, S.size() - start_index)));

    minus_position.push_back(values.size());

    for (int i = 0, m_p = 0; i < values.size(); i++)
    {
        if (i >= minus_position[m_p])
        {
            sum -= values[i];
        }
        else
        {
            sum += values[i];
        }

        // cout << sum << "\n";
    }

    cout << sum << "\n";
}
