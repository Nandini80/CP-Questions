#include <bits/stdc++.h>
using namespace std;
int longestBitonicSubsequence(vector<int>& arr, int n)
{
	vector<int> dp1(n,1),dp2(n,1);
    int maxi = 1;
	for(int i=0 ;i<n ; i++)
	{
		for(int j=0 ; j<i ; j++)
		{
			if(arr[i]>arr[j] && dp1[i] < dp1[j]+1)
			dp1[i] = dp1[j]+1;
		}
	}

	for(int i=n-1 ;i>=0 ; i--)
	{
		for(int j=n-1 ; j>i ; j--)
		{
			if(arr[i]>arr[j] && dp2[i] < dp2[j]+1)
			dp2[i] = dp2[j]+1;
		}
	}

	for(int i=0 ;i<n ; i++)
	{
		maxi = max(maxi,dp1[i]+dp2[i]-1);
	}
	return maxi;
}
