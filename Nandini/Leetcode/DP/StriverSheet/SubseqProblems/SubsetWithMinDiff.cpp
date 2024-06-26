#include <bits/stdc++.h>
using namespace std;
int minSubsetSumDifference(vector<int> &arr, int n)
{
    int total = 0;
    int mini = 1e9;
    for (int i = 0; i < n; i++)
        total += arr[i];
    int k = total;
    vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));

    for (int i = 0; i < n; i++)
        dp[i][0] = true;

    if (arr[0] <= k)
        dp[0][arr[0]] = true;

    for (int i = 1; i < n; i++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool Nottake = dp[i - 1][target];
            bool take = false;
            if (arr[i] <= target)
                take = dp[i - 1][target - arr[i]];
            dp[i][target] = take | Nottake;
        }
    }

    for (int i = 0; i <= total / 2; i++)
    {
        if (dp[n - 1][i])
        {
            int s1 = i;
            int s2 = total - i;
            mini = min(mini, abs(s1 - s2));
        }
    }
    return mini;
}
