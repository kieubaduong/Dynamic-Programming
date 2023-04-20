#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<long long> current(n + 1, -1);
    vector<long long> next(n + 1, -1);

    current[0] = 1;
    for(int i=1; i<=n; i++)
    {
        current[i] = 0;
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i<=j)
            {
                next[j] = current[j] + next[j-i];
            }
            else
            {
                next[j] = current[j];
            }
        }
        current = next;
    }

    cout << current[n];
}
