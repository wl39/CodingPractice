#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(int req[], int act[]);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int count, s, p;
    string str;
    int a, c, g, t;

    int req[26] = {0};
    int act[26] = {0};

    cin >> s >> p >> str >> a >> c >> g >> t;

    req['A' - 'A'] = a;
    req['C' - 'A'] = c;
    req['G' - 'A'] = g;
    req['T' - 'A'] = t;

    for (int i = 0; i < p; i++)
    {
        act[str[i] - 'A']++;
    }

    if (check(req, act))
    {
        count++;
    }

    for (int i = p; i < str.length(); i++)
    {
        act[str[i - p] - 'A']--;
        act[str[i] - 'A']++;

        if (check(req, act))
        {
            count++;
        }
    }

    cout << count << '\n';
}

bool check(int req[], int act[])
{
    return req['A' - 'A'] <= act['A' - 'A'] && req['C' - 'A'] <= act['C' - 'A'] && req['G' - 'A'] <= act['G' - 'A'] && req['T' - 'A'] <= act['T' - 'A'];
}