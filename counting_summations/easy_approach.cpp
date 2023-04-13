#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<long long>> arr(n + 1, vector<long long>(n + 1, -1));
    arr[0][0] = 1;
    for (int j = 1; j <= n; j++)
    {
        arr[0][j] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i <= j)
            {
                arr[i][j] = arr[i - 1][j] + arr[i][j - i];
            }
            else
            {
                arr[i][j] = arr[i - 1][j];
            }
        }
    }

    cout << arr[n][n];
}
