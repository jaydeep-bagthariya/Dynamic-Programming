//in this problem we have to find number of subset whose difference is given number.
 
#include<bits/stdc++.h>
using namespace std;

    int Count(vector<int> arr, int diff, int n, int range)
    {
        int dp[n+1][range+1];
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<range+1;j++)
            {
                if(j==0) dp[i][j] = 1;
                else if(i==0 && j!=0) dp[i][j] = 0;
                else if(arr[i-1]<=j)
                {
                    dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][range];
    }
    int main()
    {
        vector<int> arr = {1,1,2,3};
        int diff = 1;

        int sum = 0;
        for(int i : arr)
            sum += i;
        
        int range = (sum-diff)/2;

        int ans = Count(arr, diff, arr.size(), range);
        cout <<ans;
    }