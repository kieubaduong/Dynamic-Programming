#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, -1));
    dp[0][0] = 1;
    for (int j = 1; j <= n; j++)
    {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i <= j)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - i];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[n][n];
}
