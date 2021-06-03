//   ****** Partition a set into two subsets such that the difference of subset sums is minimum  ******

// Given a set of integers, the task is to divide it into two sets S1 and S2 such that the 
// absolute difference between their sums is minimum. 
// If there is a set S with n elements, then if we assume Subset1 has m elements, 
// Subset2 must have n-m elements and the value of abs(sum(Subset1) – sum(Subset2)) should be minimum.
// Example: 

// Input:  arr[] = {1, 6, 11, 5} 
// Output: 1
// Explanation:
// Subset1 = {1, 5, 6}, sum of Subset1 = 12 
// Subset2 = {11}, sum of Subset2 = 11   


//solution with dynamic programming
#include<bits/stdc++.h>
using namespace std;

void range(vector<int> &arr, vector<int> &ans, int sum,int begin)
{
    if(begin==arr.size()) 
    {
        ans.push_back(sum);
        return;
    }
    range(arr,ans,sum+arr[begin],begin+1);
    range(arr,ans,sum,begin+1);
}

void Sum(vector<int> &arr, int sum, int n, vector<int>& ans)
{
    bool dp[n+1][sum+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(j==0) dp[i][j] = true;
            else if(i==0 && j!=0) dp[i][j] = false;
            else if(arr[i-1]<=j)
            {
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    for(int i=0;i<=sum/2;i++)
        if(dp[n][i]) ans.push_back(i);
    
}

int main()
{
    vector<int> arr = {1,6,11,5};
    vector<int> ans;

    int s = 0;
    for(int i : arr)
        s += i;

    int n = arr.size();
    Sum(arr,s,n,ans);
    for(auto i : ans)
        cout << i << " ";
    int res = INT_MAX;
    for(int j=0;j<ans.size();j++)
    {
        int temp = s-2*ans[j];
        res = min(res,temp);
    }
    cout << endl<< res;
}


//I have solved this problem this way 
    // #include<bits/stdc++.h>
    // using namespace std;

    // void range(vector<int> &arr, vector<int> &ans, int sum,int begin)
    // {
    //     if(begin==arr.size()) 
    //     {
    //         ans.push_back(sum);
    //         return;
    //     }
    //     range(arr,ans,sum+arr[begin],begin+1);
    //     range(arr,ans,sum,begin+1);
    // }
    // int main()
    // {
    //     vector<int> arr = {1,6,11,5};
    //     vector<int> ans;

    //     int s = 0;
    //     for(int i : arr)
    //         s += i;

    //     int sum=0;
    //     range(arr,ans,sum,0);
    //     sort(ans.begin(),ans.end());

    //     for(int i : ans)
    //         cout << i << " ";
            
    //     int t = s/2;
    //     int i;
    //     for(i=0;i<ans.size();i++)
    //         if(ans[i]>t) break;
        
    //     int res = INT_MAX;
    //     for(int j=0;j<i;j++)
    //     {
    //         int temp = s-2*ans[j];
    //         res = min(res,temp);
    //     }
    //     cout << endl<< res;
    // }