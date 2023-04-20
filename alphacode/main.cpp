    #include <iostream>
    #include <vector>

    using namespace std;

    bool isSmallerThan26(char a, char b)
    {
        if (a >= '3')
            return false;
        if (a == '2' && b >= '7')
            return false;
        return true;
    }

    int main()
    {
        string s;
        while (true)
        {
            cin >> s;
            if (s == "0")
                break;
            vector<long long> dp(s.length(), 0);
            dp[0] = 1;
            if (s.length() >= 2)
            {
                if (isSmallerThan26(s[0], s[1]))
                {
                    if (s[1] == '0')
                    {
                        dp[1] = 1;
                    }
                    else
                    {
                        dp[1] = 2;
                    }
                }
                else
                {
                    dp[1] = dp[0];
                }
            }
            for (int i = 2; i < s.length(); i++)
            {
                if (isSmallerThan26(s[i - 1], s[i]))
                {
                    if (s[i] == '0')
                    {
                        dp[i] = dp[i - 2];
                    }
                    else if (s[i - 1] == '0')
                    {
                        dp[i] = dp[i - 1];
                    }
                    else
                    {
                        dp[i] = dp[i - 1] + dp[i - 2];
                    }
                }
                else
                {
                    dp[i] = dp[i - 1];
                }
            }
            cout << dp[s.length() - 1] << endl;
        }
    }