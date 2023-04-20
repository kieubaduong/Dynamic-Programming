#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<long long, long long> dp;

long long find(long long n)
{
    if (dp.find(n) == dp.end())
    {
        dp[n] = max(n, find(n / 2) + find(n / 3) + find(n / 4));
    }
    return dp[n];
}

int main()
{
    long long n;
    dp[0] = 0;
    while (cin >> n)
    {
        cout << find(n) << endl;
    }
    return 0;
}