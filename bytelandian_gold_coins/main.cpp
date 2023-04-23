#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<long long, long long> dp;

long long maxCoin(long long n)
{
    if (dp.find(n) == dp.end())
    {
        dp[n] = max(n, maxCoin(n / 2) + maxCoin(n / 3) + maxCoin(n / 4));
    }
    return dp[n];
}

int main()
{
    long long n;
    dp[0] = 0;
    while (cin >> n)
    {
        cout << maxCoin(n) << endl;
    }
    return 0;
}