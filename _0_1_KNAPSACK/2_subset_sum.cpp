#include<bits/stdc++.h>
using namespace std;
bool Sum(int val[], int n , int sum)
{
    if(sum==0) return true;
    else if(sum<0 || n==0) return false;
    if(val[n-1]<=sum)
    {
        // if(Sum(val,n-1,sum-val[n-1])) return true;
        // else if(Sum(val,n-1,sum)) return true;
        // else return false;
        return Sum(val,n-1,sum-val[n-1]) || Sum(val,n-1,sum);
    }
    else return Sum(val,n-1,sum);
}

bool Sum2(int val[], int n , int sum)   
{
    bool dp[n+1][sum+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(j==0) dp[i][j]=true;
            else if(i==0 && j!=0) dp[i][j]=false;
            else if(val[i-1]<=j)
            {
                // if(dp[i-1][j-val[i-1]]) dp[i][j] = true;
                // else if(dp[i-1][j]) dp[i][j] = true;
                // else dp[i][j] = false;

                dp[i][j] = (dp[i-1][j-val[i-1]] || dp[i-1][j]);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}
int main()
{
    int wt[] = {1,3,7,8,10};
    int sum = 13;
    int n = sizeof(wt) / sizeof(wt[0]);

    if(Sum(wt,n,sum)) cout << "Yes" << endl;
    else cout << "No" << endl;

    if(Sum2(wt,n,sum)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}