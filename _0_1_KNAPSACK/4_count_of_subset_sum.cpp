#include<bits/stdc++.h>
using namespace std;
void Count(int arr[], int n, int sum,int& count)
{
    if(sum==0 && n==0) count++;
    if(sum<0 || n==0) return;
    if(arr[n-1]<=sum)
    {
        Count(arr,n-1,sum-arr[n-1],count);
        Count(arr,n-1,sum,count);
    }
    else Count(arr,n-1,sum,count);
}
int Count2(int arr[], int n, int sum)
{
    int dp[n+1][sum+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(j==0) dp[i][j]=1;
            else if(i==0 && j!=0) dp[i][j]=0;
            else if(arr[i-1]<=j)
            {
                dp[i][j]=dp[i-1][j-arr[i-1]]+dp[i-1][j];
            }
            else dp[i][j] = dp[i-1][j];
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[n][sum];
}
int main()
{
    int arr[] = {2,3,5,6,8,10};
    int sum = 10;
    int n = sizeof(arr) / sizeof(arr[0]);

    int count = 0;
    Count(arr,n,sum,count);
    cout << count << endl;

    cout << Count2(arr,n,sum);
    return 0;
}