#include <iostream>

using namespace std;

/**
 * 0 1 2 3 4
 * 1 1 2 3 4
 * 2 2 3 4 5
 * 3 3 4 5 6
 * 4 4 5 6 7
 *
 *
 * 0 1 2 3 4
 * 1 1 3 6 10
 * 2 3 8 15
 * 3
 * 4
 *
 */
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 0, m = 0;

    cin >> n >> m;

    int s[1025][1025];

    for (int y = 1; y <= n; y++)
    {
        int temp;
        for (int x = 1; x <= n; x++)
        {
            cin >> temp;

            s[y][x] = s[y][x - 1] + s[y - 1][x] - s[y - 1][x - 1] + temp;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int x1, y1, x2, y2;

        cin >> y1 >> x1 >> y2 >> x2;

        cout << s[y2][x2] - s[y2][x1 - 1] - s[y1 - 1][x2] + s[y1 - 1][x1 - 1] << "\n";
    }
}