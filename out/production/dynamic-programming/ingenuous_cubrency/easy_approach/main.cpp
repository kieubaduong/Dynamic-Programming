#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
    vector<vector<long long>> dp(22, vector<long long>(10000, -1));
    dp[0][0] = 1;

    for (int j = 1; j <= 9999; j++)
    {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= 21; i++)
    {
        for (int j = 0; j <= 9999; j++)
        {
            if (i * i * i <= j)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - i * i * i];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    int m, v;
    while (cin >> v)
    {
        m = cbrt(v);
        if (m > 21)
        {
            m = 21;
        }
        cout << dp[m][v] << endl;
    }
}

