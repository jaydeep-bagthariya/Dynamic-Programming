//  ******  Coin Change | DP-7 ******

// Given a value N, if we want to make change for N cents, and we have infinite supply of each
// of S = { S1, S2, .. , Sm} valued coins, how many ways can we make the change? 
// The order of coins doesn’t matter.
// For example, for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. 
// So output should be 4. For N = 10 and S = {2, 5, 3, 6}, 
// there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. So the output should be 5.

#include<bits/stdc++.h>
using namespace std;

int numOfWays(int coin[], int sum, int n)
{
    if(sum == 0 && n==0) return 1;
    if(n==0) return 0;
    if(coin[n-1]<=sum)
    {
        return numOfWays(coin,sum-coin[n-1],n)+numOfWays(coin,sum,n-1);
    }
    else return numOfWays(coin,sum,n-1);
}

int numOfWays2(int coin[], int sum, int n)
{
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(j==0) dp[i][j] = 1;
            else if(i==0 && j!=0) dp[i][j] = 0;
            else if(coin[i-1]<=j)
                dp[i][j] = dp[i][j-coin[i-1]]+dp[i-1][j];
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}
int main()
{
    int coin[] = {1,2,3};
    int sum = 5;
    int n = sizeof(coin) / sizeof(coin[0]);

    cout << numOfWays(coin,sum,n) << endl;

    //for tabulation method
    cout << numOfWays2(coin,sum,n);
    return 0;
}