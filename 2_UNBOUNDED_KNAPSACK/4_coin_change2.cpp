//  ****** Find minimum number of coins that make a given value ****** (WATCH LEETCODE 322. COIN CHANGE)

// Given a value V, if we want to make change for V cents, and we have infinite supply of each of 
// C = { C1, C2, .. , Cm} valued coins, what is the minimum number of coins to make the change? 
// If it’s not possible to make change, print -1.

// Examples:  

// Input: coins[] = {25, 10, 5}, V = 30
// Output: Minimum 2 coins required
// We can use one coin of 25 cents and one of 5 cents 

// Input: coins[] = {9, 6, 5, 1}, V = 11
// Output: Minimum 2 coins required
// We can use one coin of 6 cents and 1 coin of 5 cents

#include<bits/stdc++.h>
using namespace std;

int minCoinWithRec(int coin[], int sum, int n,int count)
{
    if(sum == 0) return count;
    if(n==0) return INT_MAX;
    if(coin[n-1]<=sum)
    {
        return min(minCoinWithRec(coin,sum-coin[n-1],n,count+1),minCoinWithRec(coin,sum,n-1,count));
    }
    else return minCoinWithRec(coin,sum,n-1,count);
}

int minCoin(int coin[], int sum, int n)
{
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(i==0) dp[i][j] = INT_MAX-1;
            else if(j==0 && i!=0) dp[i][j] = 0;
            else if(coin[i-1]<=j)
                dp[i][j] = min(dp[i][j-coin[i-1]]+1,dp[i-1][j]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}
int main()
{
    int coin[] = {9, 6, 5, 1};
    int sum = 11;
    int n = sizeof(coin) / sizeof(coin[0]);

    int count = 0;
    cout << minCoinWithRec(coin,sum,n,count) << endl;

    //for tabulation method
    cout << minCoin(coin,sum,n);
    return 0;
}