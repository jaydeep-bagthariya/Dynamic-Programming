//******Cutting a Rod | DP-13  *******


// Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n. 
// Determine the maximum value obtainable by cutting up the rod and selling the pieces. For example, 
// if length of the rod is 8 and the values of different pieces are given as following, 
// then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6) 

// length   | 1   2   3   4   5   6   7   8  
// --------------------------------------------
// price    | 1   5   8   9  10  17  17  20

// And if the prices are as following, then the maximum obtainable value is 24 
// (by cutting in eight pieces of length 1) 

// length   | 1   2   3   4   5   6   7   8  
// --------------------------------------------
// price    | 3   5   8   9  10  17  17  20



//this is same question as unbounded knapsack 
#include<bits/stdc++.h>
using namespace std;

int withRec(int size, int length[], int price[], int n, vector<vector<int>>& dp)
{
    if(n==0 || size==0) return 0;
    if(dp[n][size] != -1) return dp[n][size];
    if(length[n-1]<=size)
    {
        return dp[n][size]=max(price[n-1]+withRec(size-length[n-1],length,price,n,dp),withRec(size,length,price,n-1,dp));
    }
    else return dp[n][size]=withRec(size,length,price,n-1,dp);
}

int unboundedknapSack(int size, int length[], int price[], int n)
{
    int dp[n+1][size+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=size+1;j++)
        {
            if(i==0 || j==0) dp[i][j] = 0;
            else if(length[i-1]<=j)
                dp[i][j] = max(price[i-1] + dp[i][j-length[i-1]], dp[i-1][j]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][size];
}

int main()
{
    int length[] = {1,2,3,4,5,6,7,8 };
    int price[] = {3,5,8,9,10,17,17,20};
    int size = 8;
    int n = sizeof(price) / sizeof(price[0]);

    vector<vector<int>>dp(n+1,vector<int>(size+1,-1));  //memoization
    cout << withRec(size,length,price, n, dp) << endl;

    //for tabulation method
    cout << unboundedknapSack(size,length,price,n);
    return 0;
}