//   ******  416. Partition Equal Subset Sum  ****** 

// Given a non-empty array nums containing only positive integers,
// find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

 

// Example 1:

// Input: nums = [1,5,11,5]
// Output: true
// Explanation: The array can be partitioned as [1, 5, 5] and [11].

// Example 2:

// Input: nums = [1,2,3,5]
// Output: false
// Explanation: The array cannot be partitioned into equal sum subsets.
 

//same problem he subset sum jaisi hi
#include<bits/stdc++.h>
using namespace std;

bool partition(int arr[], int sum, int n)
{
    bool dp[n+1][sum+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(i==0) dp[i][j]=false;
            else if(j==0) dp[i][j]=true;
            else if(arr[i-1]<=j)
            {
                dp[i][j] =  dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}
int main()
{
    int arr[] = {1,5,11,5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int sum = 0;
    for(int i : arr)
        sum+=i;
    if(sum%2) cout << "False";
    else if(partition(arr,sum/2,n)) cout << "True";
    else cout << "False";
    return 0;
}