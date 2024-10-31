#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;

    cin >> n;

    int count = 1, sum = 1;

    int start_index = 1, end_index = 1;

    while (end_index != n)
    {
        if (sum > n)
        {
            sum -= start_index++;
        }
        else if (sum < n)
        {
            sum += ++end_index;
        }
        else
        {
            count++;
            sum += ++end_index;
        }
    }

    cout << count << '\n';
}