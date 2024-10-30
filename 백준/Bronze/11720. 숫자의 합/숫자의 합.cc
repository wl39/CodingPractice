#include <iostream>

using namespace std;

int main()
{
    int n = 0;

    std::cin >> n;

    string input;

    std::cin >> input;

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += input[i] - '0';
    }

    std::cout << sum << '\n';
}