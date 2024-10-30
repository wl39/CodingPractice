#include <iostream>

using namespace std;

int main()
{
    int n = 0;

    std::cin >> n;

    int score[1000] = {0};

    float max = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> score[i];

        if (score[i] > max)
        {
            max = score[i];
        }
    }

    float final_score = 0;

    for (int i = 0; i < n; i++)
    {
        final_score += (score[i] / max) * 100;
    }

    cout << final_score / n;
}