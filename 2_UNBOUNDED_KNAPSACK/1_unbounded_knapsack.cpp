// Unbounded Knapsack (Repetition of items allowed)

// Given a knapsack weight W and a set of n items with certain value vali and weight wti, 
// we need to calculate the maximum amount that could make up this quantity exactly. 
// This is different from classical Knapsack problem, 
// here we are allowed to use unlimited number of instances of an item.

// Examples: 

// Input : W = 100
//        val[]  = {1, 30}
//        wt[] = {1, 50}
// Output : 100
// There are many ways to fill knapsack.
// 1) 2 instances of 50 unit weight item.
// 2) 100 instances of 1 unit weight item.
// 3) 1 instance of 50 unit weight item and 50
//    instances of 1 unit weight items.
// We get maximum value with option 2.

// Input : W = 8
//        val[] = {10, 40, 50, 70}
//        wt[]  = {1, 3, 4, 5}       
// Output : 110 
// We get maximum value with one unit of
// weight 5 and one unit of weight 3.

#include<bits/stdc++.h>
using namespace std;

int knapSack(int W, int wt[], int val[], int n, vector<vector<int>>&dp)
{
    if(n==0 || W==0) return 0;
    if(dp[n][W]!=-1) return dp[n][W];
    if(wt[n-1]<=W)
    {
        return dp[n][W]=max(val[n-1]+knapSack(W-wt[n-1], wt, val, n,dp),knapSack(W,wt,val,n-1,dp));
    }
    else
    {
        return dp[n][W]=knapSack(W,wt,val,n-1,dp);
    }
}


//tabulation method
int knapSack2(int W, int wt[], int val[], int n)
{
    int dp[n+1][W+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<W+1;j++)
        {
            if(i==0 || j==0) dp[i][j]=0;
            else if(wt[i-1]<=j)
            {
                dp[i][j]=max(val[i-1]+dp[i][j-wt[i-1]],dp[i-1][j]);
            }
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][W];
}
int main()
{
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 35;
    int n = sizeof(val) / sizeof(val[0]);
    vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
    cout << knapSack(W, wt, val, n,dp);

    //for tabulation method
    cout << endl << knapSack2(W,wt,val,n);
    return 0;
}