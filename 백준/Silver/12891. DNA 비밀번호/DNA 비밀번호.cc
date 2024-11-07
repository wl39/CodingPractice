#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, result = 0;

    cin >> N >> M;

    string s;

    cin >> s;

    int T[26] = {0};
    int C[26] = {0};

    cin >> T['A' - 'A'] >> T['C' - 'A'] >> T['G' - 'A'] >> T['T' - 'A'];

    for (int i = 0; i < M; i++)
    {
        C[s[i] - 'A']++;
    }

    if (C['A' - 'A'] >= T['A' - 'A'] && C['C' - 'A'] >= T['C' - 'A'] && C['G' - 'A'] >= T['G' - 'A'] && C['T' - 'A'] >= T['T' - 'A'])
    {
        result++;
    }

    for (int i = M; i < N; i++)
    {
        C[s[i - M] - 'A']--;
        C[s[i] - 'A']++;

        if (C['A' - 'A'] >= T['A' - 'A'] && C['C' - 'A'] >= T['C' - 'A'] && C['G' - 'A'] >= T['G' - 'A'] && C['T' - 'A'] >= T['T' - 'A'])
        {
            result++;
        }
    }

    cout << result << endl;
}